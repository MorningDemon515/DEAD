
#include "..\DEAD\DEADmain.h"

class ogg
{
public:
      bool LoadOGGFile(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
};