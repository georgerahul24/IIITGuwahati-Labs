cmake_minimum_required(VERSION 3.25)
project(LevelOrder C)

set(CMAKE_C_STANDARD 23)

add_executable(LevelOrder main.c Queue_Operations.c Queue_Operations.h)
