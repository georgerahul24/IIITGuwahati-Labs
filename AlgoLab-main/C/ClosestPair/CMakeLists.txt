cmake_minimum_required(VERSION 3.26)
project(ClosestPair)

set(CMAKE_CXX_STANDARD 23)

add_executable(ClosestPair main.cpp
        Point.hpp
        ONSquare.hpp
        MergeSort.hpp
        ONLogN.hpp)
