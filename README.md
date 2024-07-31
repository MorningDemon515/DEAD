# Direct Electronic Audio Display

# Introduce 

DEAD stands for Direct Electronic Audio Display (not the one you think), which is an audio library that simplifies OpenAL Soft and makes programming easier!

You need to add the source code from src to your code and correctly include and link third party libraries in the third-party folder 

# Document

You can access online documents ： http://deadlib.free.nf

# How To Build?

## Require

- You need Visual Studio 2019 or higher version
- You need CMake v3.16 or higher version

## Start Build

- Clone This Repository
- Open the directory of the repository
- Then enter:
- mkdir build
- cd build
- cmake -G "MinGW Makefiles" .. 
- cmake --build .
- Construction completed! You can find DEAD.lib and DEAD.dll in build\debug\
