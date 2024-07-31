
#include "DEADogg.h"

//-----------------------------------------OGG-----------------------------------------------------

/**
 * @brief Loads an OGG file into memory.
 * 
 * This function reads an OGG file and extracts its audio data, format, and frequency.
 * 
 * @param filename The path to the OGG file.
 * @param buffer A vector to hold the audio data read from the file.
 * @param format A reference to store the audio format (e.g., mono or stereo, 16-bit).
 * @param freq A reference to store the sample rate (frequency) of the audio data.
 * @return True if the file was successfully read and parsed, false otherwise.
 */

bool LoadOGGFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
    // Open the file 
    FILE* file = fopen(filename, "rb");
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    OggVorbis_File vorbisFile;
    // Open the Ogg Vorbis file
    if (ov_open(file, &vorbisFile, nullptr, 0) < 0) {
        std::cerr << "Failed to open OggVorbis file: " << filename << std::endl;
        fclose(file);
        return false;
    }
    
    // Get information about the Ogg Vorbis file
    vorbis_info* vorbisInfo = ov_info(&vorbisFile, -1);
    freq = vorbisInfo->rate;

     // Determine the format based on the number of channels
    format = (vorbisInfo->channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;

    long samples;
    int bitStream;
    char array[4096];// Buffer to hold audio data read from the file

    // Read the audio data in chunks
    while ((samples = ov_read(&vorbisFile, array, sizeof(array), 0, 2, 1, &bitStream)) > 0) {
        // Append the read data to the buffer
        buffer.insert(buffer.end(), array, array + samples);
    }
    
    // Clean up and close the Ogg Vorbis file
    ov_clear(&vorbisFile);
    return true;
}