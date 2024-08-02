// DEAD.h
#ifndef DEAD_H
#define DEAD_H

typedef void DEADvoid;
typedef unsigned int DEADuint;
typedef float DEADfloat;

DEADuint DEAD_Load_OGG(const char* file);
DEADuint DEAD_Load_WAV(const char* file);
DEADuint DEAD_Load_MP3(const char* file);
DEADuint DEAD_Load_AIFF(const char* file);
DEADuint DEAD_Load_FLAC(const char* file);
DEADuint DEAD_Load_AAC(const char* file);
DEADuint DEAD_Load_APE(const char* file);
DEADuint DEAD_Load_MIDI(const char* file);
DEADuint DEAD_Load_MPEG4(const char* file);

void DEAD_Init();

void DEAD_Set_Audio2D(DEADuint s, DEADfloat x, DEADfloat y);
void DEAD_Set_Audio3D(DEADuint s, DEADfloat x, DEADfloat y, DEADfloat z);
void DEAD_Loop_Audio(DEADuint s);
void DEAD_Set_Pitch(DEADuint s, DEADfloat pitch);
void DEAD_Set_Volume(DEADuint s, DEADfloat volume);
void DEAD_Set_Pan(DEADuint s, DEADfloat pan);
void DEAD_Pause_Audio(DEADuint s);
void DEAD_Resume_Audio(DEADuint s);

void DEAD_Play_Audio(DEADuint s);
void DEAD_Play_AudioToEnd(DEADuint s);

int DEAD_Get_Error();

void DEAD_Free();
void DEAD_Free_Audio(DEADuint audio);

#endif // DEAD_H