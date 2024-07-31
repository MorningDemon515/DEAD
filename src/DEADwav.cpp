
#include "DEADwav.h"

//-----------------------------------------WAV-----------------------------------------------------------

/**
 * @brief Loads a WAV file into memory.
 * 
 * This function reads a WAV file and extracts its audio data, format, and frequency.
 * 
 * @param filename The path to the WAV file.
 * @param data A vector to hold the audio data read from the file.
 * @param format A reference to store the audio format (e.g., mono or stereo, 8-bit or 16-bit).
 * @param freq A reference to store the sample rate (frequency) of the audio data.
 * @return True if the file was successfully read and parsed, false otherwise.
 */

bool LoadWAVFile(const char* filename, std::vector<char> &data, ALenum &format, ALsizei &freq)
{
    // Open the file 
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    char type[4];
    // Read the "RIFF" chunk descriptor
    file.read(type, 4); // "RIFF"
    file.ignore(4); // file size
    file.read(type, 4); // "WAVE"

    // Read the "fmt " subchunk
    file.read(type, 4); // "fmt "
    file.ignore(4); // chunk size

    // Read the format type and number of channels
    short formatType, channels;
    file.read(reinterpret_cast<char*>(&formatType), sizeof(short));
    file.read(reinterpret_cast<char*>(&channels), sizeof(short));

    // Read the sample rate
    file.read(reinterpret_cast<char*>(&freq), sizeof(int));
    file.ignore(6); // Byte rate, Block align

     // Read the bits per sample
    short bitsPerSample;
    file.read(reinterpret_cast<char*>(&bitsPerSample), sizeof(short));

    // Read the "data" subchunk
    file.read(type, 4); // "data"

     // Read the size of the data
    int dataSize;
    file.read(reinterpret_cast<char*>(&dataSize), sizeof(int));
    
    // Resize the data vector to hold the audio data
    data.resize(dataSize);

    // Read the audio data into the vector
    file.read(data.data(), dataSize);
    
    // Determine the OpenAL format based on the number of channels and bits per sample
    if (channels == 1) {
        if (bitsPerSample == 8) {
            format = AL_FORMAT_MONO8;
        } else if (bitsPerSample == 16) {
            format = AL_FORMAT_MONO16;
        }
    } else if (channels == 2) {
        if (bitsPerSample == 8) {
            format = AL_FORMAT_STEREO8;
        } else if (bitsPerSample == 16) {
            format = AL_FORMAT_STEREO16;
        }
    }

    return true;
}