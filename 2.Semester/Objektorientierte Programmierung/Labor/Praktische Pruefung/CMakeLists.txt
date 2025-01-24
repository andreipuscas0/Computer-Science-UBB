cmake_minimum_required(VERSION 3.27)
project(Praktische_Pruefung)

set(CMAKE_CXX_STANDARD 17)

add_executable(Praktische_Pruefung main.cpp
        Pharmacy.cpp
        Repository.cpp
        Controller.cpp
        UI.cpp
        Test.cpp)
