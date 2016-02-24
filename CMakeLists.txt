cmake_minimum_required(VERSION 3.2)
project(Rubkis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")
find_package( OpenCV REQUIRED )


set(SOURCE_FILES src/main.cpp src/rCube.cpp headers/rCube.hpp headers/color.hpp headers/moves.hpp src/solver.cpp headers/solver.hpp src/imageProcessor.cpp headers/imageProcessor.hpp)
add_executable(Rubkis ${SOURCE_FILES})
target_link_libraries( Rubkis ${OpenCV_LIBS})
