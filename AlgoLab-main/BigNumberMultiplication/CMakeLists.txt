cmake_minimum_required(VERSION 3.26)
project(BigNumberMultiplication)

set(CMAKE_CXX_STANDARD 23)

add_executable(BigNumberMultiplication main.cpp
        BigNumberMultiplicationN2.hpp
        BigNumberMultiplicationN.hpp
        BigNumberMultiplicationDivideAndConquer.cpp)
