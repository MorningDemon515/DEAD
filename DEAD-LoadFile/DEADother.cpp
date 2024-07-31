
#include "DEADother.h"

bool other::LoadAIFFFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
    // open file
    SF_INFO sfInfo;
    SNDFILE* sndFile = sf_open(filename, SFM_READ, &sfInfo);
    if (!sndFile) {
        std::cerr << "Error opening file: " << sf_strerror(sndFile) << std::endl;
        return false;
    }

    // check file format AIFF
    if (sfInfo.format & SF_FORMAT_AIFF == 0) {
        std::cerr << "File is not in AIFF format." << std::endl;
        sf_close(sndFile);
        return false;
    }

    // set audio format
    if (sfInfo.channels == 1) {
        format = AL_FORMAT_MONO16;
    } else if (sfInfo.channels == 2) {
        format = AL_FORMAT_STEREO16;
    } else {
        std::cerr << "Unsupported channel count: " << sfInfo.channels << std::endl;
        sf_close(sndFile);
        return false;
    }

    // read audio
    sf_count_t numFrames = sfInfo.frames * sfInfo.channels;
    buffer.resize(numFrames * sizeof(short)); // 16bit
    sf_count_t numRead = sf_read_short(sndFile, reinterpret_cast<short*>(buffer.data()), numFrames);
    if (numRead != numFrames) {
        std::cerr << "Failed to read complete file: " << sf_strerror(sndFile) << std::endl;
        sf_close(sndFile);
        return false;
    }

    // set freq
    freq = sfInfo.samplerate;

    // close file
    sf_close(sndFile);

    return true;
}

bool other::LoadFLACFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq) {
   
    SF_INFO sfInfo;
    SNDFILE* sndFile = sf_open(filename, SFM_READ, &sfInfo);
    if (!sndFile) {
        std::cerr << "Error opening file: " << sf_strerror(sndFile) << std::endl;
        return false;
    }

    if ((sfInfo.format & SF_FORMAT_FLAC) != SF_FORMAT_FLAC) {
        std::cerr << "File is not in FLAC format." << std::endl;
        sf_close(sndFile);
        return false;
    }

    if (sfInfo.channels == 1) {
        format = AL_FORMAT_MONO16;
    } else if (sfInfo.channels == 2) {
        format = AL_FORMAT_STEREO16;
    } else {
        std::cerr << "Unsupported channel count: " << sfInfo.channels << std::endl;
        sf_close(sndFile);
        return false;
    }

    sf_count_t numFrames = sfInfo.frames * sfInfo.channels;
    buffer.resize(numFrames * sizeof(short)); 
    sf_count_t numRead = sf_read_short(sndFile, reinterpret_cast<short*>(buffer.data()), numFrames);
    if (numRead != numFrames) {
        std::cerr << "Failed to read complete file: " << sf_strerror(sndFile) << std::endl;
        sf_close(sndFile);
        return false;
    }

    freq = sfInfo.samplerate;

    sf_close(sndFile);

    return true;
}

bool other::LoadAACFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
     // Open the file
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::wcerr << L"Failed to open file: " << filename << std::endl;
        return false;
    }

    // Read the file content into a buffer
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    buffer.resize(size);
    if (!file.read(buffer.data(), size)) {
        std::wcerr << L"Failed to read file: " << filename << std::endl;
        return false;
    }
    file.close();

    // Initialize FAAD2 library
    NeAACDecHandle decoder = NeAACDecOpen();
    if (!decoder) {
        std::cerr << "Failed to initialize FAAD2 decoder" << std::endl;
        return false;
    }

    // Initialize the decoder with the AAC file data
    unsigned char* buffer_data = reinterpret_cast<unsigned char*>(buffer.data());
    int buffer_size = static_cast<int>(buffer.size());

    NeAACDecFrameInfo frame_info;
    void* pcm_data = NeAACDecDecode(decoder, &frame_info, buffer_data, buffer_size);

    if (!pcm_data) {
        std::cerr << "Failed to decode AAC data" << std::endl;
        NeAACDecClose(decoder);
        return false;
    }

    // Get the sample rate and channels from the frame info
    freq = frame_info.samplerate;
    int channels = frame_info.channels;

    // Determine the AL format based on channels
    switch (channels) {
        case 1:
            format = AL_FORMAT_MONO16;
            break;
        case 2:
            format = AL_FORMAT_STEREO16;
            break;
        default:
            std::cerr << "Unsupported number of channels: " << channels << std::endl;
            NeAACDecClose(decoder);
            return false;
    }

    // Copy PCM data to buffer (in reality, you might want to handle more advanced buffer management)
    buffer.assign(reinterpret_cast<char*>(pcm_data), reinterpret_cast<char*>(pcm_data) + frame_info.samples * channels * sizeof(short));

    NeAACDecClose(decoder);
    return true;
}

int other::readCallback(ape_stream *stream, void *buffer, int size)
{
    FILE* file = reinterpret_cast<FILE*>(stream->user_data);
    size_t bytesRead = fread(buffer, 1, size, file);
    return static_cast<int>(bytesRead);
}

bool other::LoadAPEFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
     //open APE file
    ape_file* apeFile = nullptr;
    if (ape_file_open(filename, 1, &apeFile) < 0 || apeFile == nullptr) {
        std::cerr << "Failed to open APE file: " << filename << std::endl;
        return false;
    }

    // get APE file
    int channels = ape_file_get_channels(apeFile);
    freq = ape_file_get_samplerate(apeFile);
    int bitsPerSample = ape_file_get_bits_per_sample(apeFile);
    int blocksPerFrame = ape_file_get_blocks_per_frame(apeFile);

    // set OpenAL format
    if (channels == 1) {
        format = (bitsPerSample == 16) ? AL_FORMAT_MONO16 : AL_FORMAT_MONO8;
    } else if (channels == 2) {
        format = (bitsPerSample == 16) ? AL_FORMAT_STEREO16 : AL_FORMAT_STEREO8;
    } else {
        std::cerr << "Unsupported number of channels: " << channels << std::endl;
        ape_file_free(apeFile);
        return false;
    }

    // file data's size
    ALsizei totalBlocks = ape_file_get_total_blocks(apeFile);
    ALsizei dataSize = totalBlocks * blocksPerFrame * (bitsPerSample / 8) * channels;

    // read file data to buffer
    buffer.resize(dataSize);

    // open and read file
    FILE* file = fopen(filename, "rb");
    if (file == nullptr) {
        std::cerr << "Failed to open file for reading" << std::endl;
        ape_file_free(apeFile);
        return false;
    }

    // Create and initialize stream objects
    ape_stream stream;
    stream.read = readCallback;  // Set the callback function for reading
    stream.seek = nullptr;       // If necessary, set appropriate seek callbacks
    stream.tell = nullptr;       // If necessary, set appropriate tell callbacks
    stream.user_data = file;     // Set the file pointer to user data

    // read data form APE file 
    int totalRead = 0;
    int bytesRead;
    while (totalRead < dataSize) {
        bytesRead = stream.read(&stream, buffer.data() + totalRead, dataSize - totalRead);
        if (bytesRead <= 0) {
            std::cerr << "Failed to read data from APE file" << std::endl;
            fclose(file);
            ape_file_free(apeFile);
            return false;
        }
        totalRead += bytesRead;
    }

    // close file
    fclose(file);

    // close APE file
    ape_file_free(apeFile);

    return true;
}

bool other::ReadFileToBuffer(const char* filename, std::vector<char>& buffer)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }
    
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    buffer.resize(size);
    if (!file.read(buffer.data(), size)) {
        std::cerr << "Failed to read file: " << filename << std::endl;
        return false;
    }
    
    return true;
}

void other::ProcessMIDIData(const std::vector<char>& buffer)
{
    for (char byte : buffer) {
        midi_receive_byte(byte);
    }
}


bool other::LoadMIDIFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
    // read MIDI file to buffer
    if (!ReadFileToBuffer(filename, buffer)) {
        return false;
    }
    
    // Initialize MIDI library
    if (midi_init() != 0) {
        std::cerr << "Failed to initialize MIDI library" << std::endl;
        return false;
    }
    
    // Process MIDI data
    ProcessMIDIData(buffer);
    
    // set OpenAL format and freq
    // These values need to be set according to the actual situation. For MIDI files, we can use default values.
    format = AL_FORMAT_MONO16; // Or AL-FORMAT_STEREO16, set according to the actual situation
    freq = 44100; // Or other appropriate frequencies
    
    return true;
}

ALenum other::GetOpenALFormat(int channels, int format)
{
    if (channels == 1) {
        switch (format) {
            case SF_FORMAT_PCM_16: return AL_FORMAT_MONO16;
            case SF_FORMAT_PCM_U8:  return AL_FORMAT_MONO8;
            case SF_FORMAT_FLOAT:  return AL_FORMAT_MONO_FLOAT32;
            default: return AL_FORMAT_MONO16;  // default format
        }
    } else if (channels == 2) {
        switch (format) {
            case SF_FORMAT_PCM_16: return AL_FORMAT_STEREO16;
            case SF_FORMAT_PCM_U8:  return AL_FORMAT_STEREO8;
            case SF_FORMAT_FLOAT:  return AL_FORMAT_STEREO_FLOAT32;
            default: return AL_FORMAT_STEREO16;  // default format
        }
    }
    return AL_FORMAT_STEREO16;  // default format
}

bool other::LoadMPEG4File(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
    // Open the audio file using libsndfile
    SF_INFO sfinfo;
    SNDFILE* sndfile = sf_open(filename, SFM_READ, &sfinfo);
    
    if (!sndfile) {
        std::cerr << "Error opening file: " << sf_strerror(NULL) << std::endl;
        return false;
    }

    // Check if the format is supported
    if (sfinfo.channels < 1 || sfinfo.channels > 2) {
        std::cerr << "Unsupported number of channels: " << sfinfo.channels << std::endl;
        sf_close(sndfile);
        return false;
    }

    if (sfinfo.samplerate <= 0) {
        std::cerr << "Invalid sample rate: " << sfinfo.samplerate << std::endl;
        sf_close(sndfile);
        return false;
    }

    // Determine the format for OpenAL based on the sample format
    format = GetOpenALFormat(sfinfo.channels, sfinfo.format & SF_FORMAT_SUBMASK);

    // Check for unsupported formats
    if (format == AL_FORMAT_STEREO16 && (sfinfo.format & SF_FORMAT_SUBMASK) != SF_FORMAT_PCM_16) {
        std::cerr << "Unsupported sample format: " << (sfinfo.format & SF_FORMAT_SUBMASK) << std::endl;
        sf_close(sndfile);
        return false;
    }

    freq = sfinfo.samplerate;

    // Calculate the buffer size and allocate memory
    std::size_t num_samples = sfinfo.frames * sfinfo.channels;
    buffer.resize(num_samples * sizeof(short)); // Adjust size for float or other types as needed

    // Read the audio data into the buffer
    if (sfinfo.format & SF_FORMAT_FLOAT) {
        // For float data
        std::vector<float> float_buffer(sfinfo.frames * sfinfo.channels);
        if (sf_read_float(sndfile, float_buffer.data(), sfinfo.frames * sfinfo.channels) != sfinfo.frames * sfinfo.channels) {
            std::cerr << "Error reading audio data: " << sf_strerror(sndfile) << std::endl;
            sf_close(sndfile);
            return false;
        }
        memcpy(buffer.data(), float_buffer.data(), buffer.size());
    } else {
        // For integer data (16-bit PCM or 8-bit PCM)
        if (sf_read_short(sndfile, reinterpret_cast<short*>(buffer.data()), num_samples) != num_samples) {
            std::cerr << "Error reading audio data: " << sf_strerror(sndfile) << std::endl;
            sf_close(sndfile);
            return false;
        }
    }

    // Clean up
    sf_close(sndfile);
    return true;
   
}

