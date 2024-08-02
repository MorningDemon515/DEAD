// DEAD.cpp
#include "../include/DEAD.h"
#include "DEADmain.h"
#include "DEADogg.h"
#include "DEADmp3.h"
#include "DEADwav.h"
#include "DEADother.h"

ALCdevice *device;
ALCcontext *context;

DEADuint DEAD_Load_OGG(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadOGGFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_WAV(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadWAVFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_MP3(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadMP3File(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_AIFF(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadAIFFFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_FLAC(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadFLACFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_AAC(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadAACFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_APE(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadAPEFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_MIDI(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadMIDIFile(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

DEADuint DEAD_Load_MPEG4(const char* file)
{
    ALuint buffer;
    ALuint source;

    std::vector<char> data;
    ALenum format;
    ALsizei freq;

    alGenBuffers(1, &buffer);
    if(!LoadMPEG4File(file,data, format, freq)) {}
    alBufferData(buffer, format, data.data(), data.size(), freq);
    
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
    alDeleteBuffers(1, &buffer);
}

void DEAD_Init()
{
    device = alcOpenDevice(nullptr);
    if(!device)
    {
        std::cout<<"Initialization failed!"<<std::endl;
    }

    context = alcCreateContext(device, nullptr);
    if(!context)
    {
        std::cout<<"Initialization failed!"<<std::endl;
    }

    alcMakeContextCurrent(context);
}

/*
DEADuint DEAD_Set_Audio(DEADuint buffer)
{
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    return source;
}
*/

void DEAD_Set_Audio2D(DEADuint s, DEADfloat x, DEADfloat y)
{
    alSource3f(s, AL_POSITION,x,y,0.0f);
}

void DEAD_Set_Audio3D(DEADuint s, DEADfloat x, DEADfloat y, DEADfloat z)
{
    alSource3f(s, AL_POSITION,x,y,z);
}

void DEAD_Loop_Audio(DEADuint s)
{
    alSourcei(s, AL_LOOPING, AL_TRUE);
}

void DEAD_Set_Pitch(DEADuint s,DEADfloat pitch)
{
    alSourcef(s, AL_PITCH, pitch); 
}

void DEAD_Set_Volume(DEADuint s,DEADfloat volume)
{
    alSourcef(s,AL_GAIN,volume);
}

void DEAD_Set_Pan(DEADuint s,DEADfloat pan)
{
    alSource3f(s, AL_POSITION,pan,0.0f,0.0f);
}

void DEAD_Pause_Audio(DEADuint s)
{
    alSourcePause(s);
}

void DEAD_Resume_Audio(DEADuint s)
{
    alSourcePlay(s);
}

void DEAD_Play_Audio(DEADuint s)
{
    alSourcePlay(s);
}

void DEAD_Play_AudioToEnd(DEADuint s)
{
    alSourcePlay(s);

    ALint state;
    do {
        alGetSourcei(s, AL_SOURCE_STATE, &state);
    } while (state == AL_PLAYING);
}

int DEAD_Get_Error()
{
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        fprintf(stderr, "DEAD Error! %s\n", alGetString(error));
        return -1;
    }

    return 0;
}

void DEAD_Free()
{
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
}

/*
void DEAD_Free_Buffer(DEADuint buffer)
{
   return alDeleteBuffers(1, &buffer);
}
*/

void DEAD_Free_Audio(DEADuint audio)
{
    return alDeleteSources(1, &audio);
}