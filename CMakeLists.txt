cmake_minimum_required(VERSION 3.2)
project(Rubkis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/rCube.cpp headers/rCube.h headers/color.h headers/moves.h)
add_executable(Rubkis ${SOURCE_FILES})
