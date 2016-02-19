cmake_minimum_required(VERSION 3.2)
project(Rubkis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")


set(SOURCE_FILES src/main.cpp src/rCube.cpp headers/rCube.hpp headers/color.hpp headers/moves.hpp src/solver.cpp headers/solver.hpp)
add_executable(Rubkis ${SOURCE_FILES})
