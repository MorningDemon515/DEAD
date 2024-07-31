
#include "DEADOther.h"

void DEADOther::LoopAudio(ALuint s)
{
    alSourcei(s, AL_LOOPING, AL_TRUE);
}

void DEADOther::SetAudioPitch(ALuint s,ALfloat p)
{
    alSourcef(s, AL_PITCH, p); 
}

void DEADOther::SetAudioVolume(ALuint s,ALfloat v)
{
    alSourcef(s,AL_GAIN,v);
}

void DEADOther::SetAudioPan(ALuint s,ALfloat p)
{
    alSource3f(s, AL_POSITION,p,0.0f,0.0f);
}

void DEADOther::SetAudio2d(ALuint s, ALfloat x,ALfloat y)
{
    alSource3f(s, AL_POSITION,x,y,0.0f);
}

void DEADOther::SetAudio3d(ALuint s, ALfloat x,ALfloat y,ALfloat z)
{
    alSource3f(s, AL_POSITION,x,y,z);
}

void DEADOther::PauseAudio(ALuint s)
{
    alSourcePause(s);
}

void DEADOther::ResumeAudio(ALuint s)
{
    alSourcePlay(s);
}