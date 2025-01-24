cmake_minimum_required(VERSION 3.27)
project(Labor1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Labor1
        app.cpp
        Graph.cpp
        Graph.h)
