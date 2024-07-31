
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

    std::cout<<"输入文件名\n";
    std::cin>>file;

    buffer = DEAD_Load_OGG(file.c_str());
    audio = DEAD_Set_Audio(buffer);
    
    DEAD_Play_AudioToEnd(audio);

    DEAD_Free();
    DEAD_Free_Audio(audio);
    DEAD_Free_Buffer(buffer);

    system("pause");
    return 0;
}