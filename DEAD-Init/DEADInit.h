
#include "..\DEAD\DEADmain.h"

class AL
{
private:    
    ALCdevice *device;
    ALCcontext *context;

public:    
    void Init();
    void Free();
};