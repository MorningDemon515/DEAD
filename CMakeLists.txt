cmake_minimum_required(VERSION 3.16)

project(DEAD)

# Set include directories
set(oggVorbis_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/include)
set(openal-soft_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party/openal-soft/include)
set(sndfile_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libsndfile/include)
set(faad2_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/include)
set(libape_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libape/include)

# Set library paths and files based on compiler
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(oggVorbis_LIBRARY
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/lib/libvorbisfile.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/lib/libvorbis.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/lib/libogg.a
    )
    set(openal-soft_LIBRARY
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/openal-soft/lib/libOpenAL32.dll.a
    )
    set(sndfile_lib
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libsndfile/lib/libsndfile.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libsndfile/lib/libtest_utils.a
    )
    set(libape_lib ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libape/lib/libape.a)
    set(faad2_lib
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/libfaad.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/libfaad.dll.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/libfaad_drm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/libfaad_drm_fixed.a
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/libfaad_fixed.a
    )
endif()

# Set source and header files
set(DEAD_CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADogg.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADwav.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADmp3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libmidi/midi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADother.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEAD.cpp
)

set(DEAD_H
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADogg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADwav.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADmp3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DEADother.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/DEAD.h
)

# Create example executable
add_executable(example ${DEAD_CPP} ${DEAD_H} ${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp)

# Include directories
target_include_directories(example PUBLIC
    ${oggVorbis_INCLUDE_DIR}
    ${openal-soft_INCLUDE_DIR}
    ${sndfile_include_dir}
    ${faad2_include_dir}
    ${libape_include_dir}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(example
    ${oggVorbis_LIBRARY}
    ${openal-soft_LIBRARY}
    ${sndfile_lib}
    ${faad2_lib}
    ${libape_lib}
)


