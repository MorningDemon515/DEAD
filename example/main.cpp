
#include <iostream>
#include <string>
#include <DEAD.h>

int main()
{
    std::string file;
    DEADuint buffer;
    DEADuint audio;
    
    DEAD_Init();
    DEAD_Get_Error();

    std::cout<<"Enter file name\n";
    std::cin>>file;

    buffer = DEAD_Load_WAV(file.c_str());
    audio = DEAD_Set_Audio(buffer);
    
    DEAD_Set_Volume(audio,0.5f);

    DEAD_Play_AudioToEnd(audio);

    DEAD_Free();
    DEAD_Free_Audio(audio);
    DEAD_Free_Buffer(buffer);

    system("pause");
    return 0;
}