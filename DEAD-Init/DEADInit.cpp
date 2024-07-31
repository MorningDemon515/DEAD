
#include "DEADInit.h"

void AL::Init()
{
    device = alcOpenDevice(nullptr);
    if(!device)
    {
        std::cout<<"Initialization failed!"<<std::endl;
    }

    context = alcCreateContext(device, nullptr);
    if(!context)
    {
        std::cout<<"Initialization failed!"<<std::endl;
    }

    alcMakeContextCurrent(context);
}

void AL::Free()
{
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
}