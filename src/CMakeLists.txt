cmake_minimum_required(VERSION 3.0)
project(cpp-snippets)

include_directories(
    include
)

set(LibraryName snippets)

add_subdirectory(../test test)

file(GLOB sources *.cpp)
add_library(${LibraryName} ${sources})
target_compile_options(${LibraryName} PUBLIC -std=c++14 -O3 -Wall -Wfloat-conversion)