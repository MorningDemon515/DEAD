
#include "DEADLoadAudio.h"

ogg og;
wav wa;
mp3 m3;
other oh;

ALuint DEADLoadAudio::LoadOGGAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!og.LoadOGGFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;

}

ALuint DEADLoadAudio::LoadWAVAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!wa.LoadWAVFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;

}

ALuint DEADLoadAudio::LoadMP3Audio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!m3.LoadMP3File(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}

ALuint DEADLoadAudio::LoadAIFFAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!oh.LoadAIFFFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}

ALuint DEADLoadAudio::LoadFLACAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!oh.LoadFLACFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}

ALuint DEADLoadAudio::LoadAACAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!oh.LoadAACFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}

ALuint DEADLoadAudio::LoadAPEAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!oh.LoadAPEFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}

ALuint DEADLoadAudio::LoadMIDIAudio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!oh.LoadMIDIFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}

ALuint DEADLoadAudio::LoadMPEG4Audio(const char* file)
{
    ALuint buffer;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!oh.LoadMPEG4File(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    return buffer;
}