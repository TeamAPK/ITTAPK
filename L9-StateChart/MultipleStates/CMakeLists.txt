cmake_minimum_required(VERSION 3.6)
project(MultipleStates)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES radio.cpp)
add_executable(MultipleStates ${SOURCE_FILES})