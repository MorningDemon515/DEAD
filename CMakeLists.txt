cmake_minimum_required (VERSION 3.16)

project (DEAD)

set(oggVorbis_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/include)
set(openal-soft_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party/openal-soft/include)

set(sndfile_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libsndfile/include)
set(faad2_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/include)
set(libape_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libape/include)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
   set(oggVorbis_LIBRARY 
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/lib/libogg.lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/lib/libvorbis_static.lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/oggVorbis/lib/libvorbisfile_static.lib
   )
   
   set(openal-soft_LIBRARY 
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/openal-soft/lib/OpenAL32.lib
   )
   
   set(sndfile_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libsndfile/lib/sndfile.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libsndfile/lib/test_utils.lib
   )

   set(libape_lib ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libape/lib/ape.lib)

   set(faad2_lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/faad.lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/faad_cli.lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/faad_drm.lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/faad_drm_fixed.lib
       ${CMAKE_CURRENT_SOURCE_DIR}/third-party/faad2/lib/faad_fixed.lib
   )
endif()

set(DEAD_CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADogg.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADwav.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADmp3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libmidi/midi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADother.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Init/DEADInit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADLoadAudio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADPlayAudio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADSetAudio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADOther.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD/DEAD.cpp
)

set(DEAD_H
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADogg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADwav.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADmp3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/libmidi/midi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-LoadFile/DEADother.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Init/DEADInit.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADLoadAudio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADPlayAudio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADSetAudio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD-Func/DEADOther.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DEAD/DEADmain.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/DEAD.h
)

add_library(DEAD SHARED#You Can Change To STATIC 
                  ${DEAD_CPP}
	  ${DEAD_H}
)

target_include_directories(DEAD PUBLIC
    ${oggVorbis_INCLUDE_DIR}
    ${openal-soft_INCLUDE_DIR}
    ${sndfile_include_dir}
    ${faad2_include_dir}
    ${libape_include_dir}
)

target_link_libraries(DEAD
    ${oggVorbis_LIBRARY}
    ${openal-soft_LIBRARY}
    ${sndfile_lib}
    ${faad2_lib}
    ${libape_lib}
)