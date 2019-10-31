cmake_minimum_required(VERSION 3.0)
project(cpp-snippets)

add_subdirectory(../libs/armadillo armadillo)

include_directories(
	../libs/armadillo/include
    loops/include
    heteroContainer/include
    pointers/include
)

file(GLOB sources
	loops/*.cpp
	heteroContainer/*.cpp
	pointers/*.cpp)

set(LibraryName snippets)

add_library(${LibraryName} ${sources})
target_compile_options(${LibraryName} PUBLIC -std=c++14 -O3 -Wall -Wfloat-conversion)

add_subdirectory(../test test)