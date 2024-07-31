
#include "DEADSetAudio.h"

ALuint DEADSetAudio::SetAudio(ALuint b)
{
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, b);
    return source;
}