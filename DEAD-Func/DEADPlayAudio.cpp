
#include "DEADPlayAudio.h"

void DEADPlayAudio::PlayAudioToEnd(ALuint s)
{
    alSourcePlay(s);

    ALint state;
    do {
        alGetSourcei(s, AL_SOURCE_STATE, &state);
    } while (state == AL_PLAYING);
}

void DEADPlayAudio::PlayAudio(ALuint s)
{
    alSourcePlay(s);
}