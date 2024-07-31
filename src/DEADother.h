
#include "DEADmain.h"
#include <sndfile.h>
#include <faad.h>
#include <ape.h>
#include "..\third-party\libmidi\midi.h"

bool LoadAIFFFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
bool LoadFLACFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
bool LoadAACFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
bool LoadAPEFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
bool LoadMIDIFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
bool LoadMPEG4File(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

static int readCallback(ape_stream *stream, void *buffer, int size);
bool ReadFileToBuffer(const char* filename, std::vector<char>& buffer);
void ProcessMIDIData(const std::vector<char>& buffer);
ALenum GetOpenALFormat(int channels, int format);
