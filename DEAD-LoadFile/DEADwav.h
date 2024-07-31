
#include "..\DEAD\DEADmain.h"

class wav
{
public:
      bool LoadWAVFile(const char* filename, std::vector<char> &data, ALenum &format, ALsizei &freq);
};