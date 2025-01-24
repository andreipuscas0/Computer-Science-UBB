cmake_minimum_required(VERSION 3.27)
project(Labor_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Labor_4 main.cpp
        Shop.cpp
        Shop.h
        Repository.cpp
        Repository.h
        UI.cpp
        UI.h
        Controller.cpp
        Controller.h)
