cmake_minimum_required(VERSION 3.26)
project(EndSem)

set(CMAKE_CXX_STANDARD 23)

add_executable(EndSem main.cpp
        Q1.hpp
        DirectedGraphWithoutWeightsVer2.hpp
        UndirectedGraphWithWeightsVer2.hpp
        Q2.hpp)
