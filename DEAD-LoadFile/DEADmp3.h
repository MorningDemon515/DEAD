
#include "..\DEAD\DEADmain.h"
#include <sndfile.h>

class mp3
{
public:
bool LoadMP3File(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

};