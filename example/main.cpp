
#include <iostream>
#include <string>
#include <DEAD.h>

int main()
{
    std::string file;
    DEADuint audio;
    
    DEAD_Init();
    DEAD_Get_Error();

    std::cout<<"Enter File Name\n";
    std::cin>>file;

    audio = DEAD_Load_OGG(file.c_str());
    
    DEAD_Play_AudioToEnd(audio);

    DEAD_Free();
    DEAD_Free_Audio(audio);

    system("pause");
    return 0;
}