cmake_minimum_required(VERSION 3.25)
project(PrintTree C)

set(CMAKE_C_STANDARD 23)

add_executable(PrintTree main.c PrintTree.h PrintTree.c)
