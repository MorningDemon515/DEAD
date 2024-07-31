
#include "..\DEAD-Init\DEADInit.h"
#include "..\DEAD-LoadFile\DEADogg.h"
#include "..\DEAD-LoadFile\DEADwav.h"
#include "..\DEAD-LoadFile\DEADmp3.h"
#include "..\DEAD-LoadFile\DEADother.h"
#include "..\include\DEAD.h"

class DEADLoadAudio 
{
public:
    ALuint LoadOGGAudio(const char* file);
    ALuint LoadWAVAudio(const char* file);
    ALuint LoadMP3Audio(const char* file);
    ALuint LoadAIFFAudio(const char* file);
    ALuint LoadFLACAudio(const char* file);
    ALuint LoadAACAudio(const char* file);
    ALuint LoadAPEAudio(const char* file);
    ALuint LoadMIDIAudio(const char* file);
    ALuint LoadMPEG4Audio(const char* file);
};