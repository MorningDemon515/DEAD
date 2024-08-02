
#include "..\include\DEAD.h"
#include "..\DEAD-Func\DEADLoadAudio.h"
#include "..\DEAD-Func\DEADPlayAudio.h"
#include "..\DEAD-Func\DEADOther.h"

DEADLoadAudio LAInstance;
DEADPlayAudio PAInstance;
DEADOther OHInstance;

AL al;
DEADLoadAudio* LA = &LAInstance;
DEADPlayAudio* PA = &PAInstance;
DEADOther* OH = &OHInstance;

DEAD(DEADuint) DEAD_Load_OGG(const char* file)
{
    return LA->LoadOGGAudio(file);
}

DEAD(DEADuint) DEAD_Load_WAV(const char* file)
{
    return LA->LoadWAVAudio(file);
}

DEAD(DEADuint) DEAD_Load_MP3(const char* file)
{
    return LA->LoadMP3Audio(file);
}

DEAD(DEADuint) DEAD_Load_AIFF(const char* file)
{
    return LA->LoadAIFFAudio(file);
}

DEAD(DEADuint) DEAD_Load_FLAC(const char* file)
{
    return LA->LoadFLACAudio(file);
}

DEAD(DEADuint) DEAD_Load_AAC(const char* file)
{
    return LA->LoadAACAudio(file);
}

DEAD(DEADuint) DEAD_Load_APE(const char* file)
{
    return LA->LoadAPEAudio(file);
}

DEAD(DEADuint) DEAD_Load_MIDI(const char* file)
{
    return LA->LoadMIDIAudio(file);
}

DEAD(DEADuint) DEAD_Load_MPEG4(const char* file)
{
    return LA->LoadMPEG4Audio(file);
}

DEAD(void) DEAD_Init()
{
    al.Init();
}

DEAD(void) DEAD_Set_Audio2D(DEADuint s, DEADfloat x,DEADfloat y)
{
    OH->SetAudio2d(s,x,y);
}

DEAD(void) DEAD_Set_Audio3D(DEADuint s, DEADfloat x,DEADfloat y,DEADfloat z)
{
    OH->SetAudio3d(s,x,y,z);
}

DEAD(void) DEAD_Loop_Audio(DEADuint s)
{
    OH->LoopAudio(s);
}

DEAD(void) DEAD_Set_Pitch(DEADuint s,DEADfloat pitch)
{
    OH->SetAudioPitch(s,pitch);
}

DEAD(void) DEAD_Set_Volume(DEADuint s,DEADfloat volume)
{
    OH->SetAudioVolume(s,volume);
}

DEAD(void) DEAD_Set_Pan(DEADuint s,DEADfloat pan)
{
    OH->SetAudioPan(s,pan);
}

DEAD(void) DEAD_Pause_Audio(DEADuint s)
{
    OH->PauseAudio(s);
}

DEAD(void) DEAD_Resume_Audio(DEADuint s)
{
    OH->ResumeAudio(s);
}

DEAD(void) DEAD_Play_Audio(DEADuint s)
{
    PA->PlayAudio(s);
}

DEAD(void) DEAD_Play_AudioToEnd(DEADuint s)
{
    PA->PlayAudioToEnd(s);
}

DEAD(int) DEAD_Get_Error()
{
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        fprintf(stderr, "DEAD Error! %s\n", alGetString(error));
        return -1;
    }

    return 0;
}

DEAD(void) DEAD_Free()
{
    al.Free();
}

DEAD(void) DEAD_Free_Audio(DEADuint audio)
{
    alDeleteSources(1, &audio);
}

