cmake_minimum_required(VERSION 4.1)
project(data_analyser)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_analyser main.cpp
        comparison/Comparer.cpp
        comparison/Comparer.h
        average/Average.cpp
        average/Average.h
        helperfun.cpp
        helperfun.h)
