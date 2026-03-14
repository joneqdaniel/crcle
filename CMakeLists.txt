cmake_minimum_required( VERSION 3.15 )

project( crcle VERSION 0.1 LANGUAGES CXX )
set(PROJECT_DESCRIPTION "crcle a C++ CRC checksum library")

include(GNUInstallDirs)

set( CMAKE_CXX_STANDARD 26 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

if( NOT CMAKE_BUILD_TYPE )
        set( CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE )
endif()

if( CMAKE_BUILD_TYPE EQUAL Debug )
	add_compile_options(-g)
endif()

if( CMAKE_GENERATOR_PLATFORM STREQUAL "x64" OR CMAKE_GENERATOR_PLATFORM STREQUAL "x86_64" OR CMAKE_GENERATOR_PLATFORM STREQUAL "AMD64" )
	add_compile_options(-mfpmath=sse)
endif()

if( NOT CMAKE_BUILD_OPTLEVEL )
	set( CMAKE_BUILD_OPTLEVEL 3 CACHE STRING "Choose the optimization level of the build" FORCE )
endif()

add_compile_options(-march=native)
add_compile_options(-O${CMAKE_BUILD_OPTLEVEL})
add_compile_options(-ftree-vectorize)
add_compile_options(-fopenmp-simd)
add_compile_options(-D_FILE_OFFSET_BITS=64)
add_compile_options(-fdata-sections)
add_compile_options(-fpermissive)
add_compile_options(-ffunction-sections)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Wno-unused-parameter)
add_compile_options(-Wno-pedantic)
add_compile_options(-Wno-narrowing)
add_link_options(-Wl,--gc-sections)
add_link_options(-Wl,--print-gc-sections)
add_link_options(-Wl,-s)

add_library( ${PROJECT_NAME} INTERFACE )
target_include_directories( ${PROJECT_NAME} INTERFACE
        PUBLIC_HEADER $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_executable( example examples/example.cpp )
target_link_libraries( example ${PROJECT_NAME} )

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers)

