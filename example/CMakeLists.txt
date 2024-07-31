cmake_minimum_required (VERSION 3.16)

project (example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(DEADlib ${CMAKE_CURRENT_SOURCE_DIR}/DEAD.lib)

add_executable(example main.cpp)

target_include_directories(example PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(example 
        ${DEADlib}
)

