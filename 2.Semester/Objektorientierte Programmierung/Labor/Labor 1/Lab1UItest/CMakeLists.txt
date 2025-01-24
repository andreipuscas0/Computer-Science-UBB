cmake_minimum_required(VERSION 3.27)
project(Lab1UItest)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1UItest main.cpp
        AutoUI.cpp
        AutoUI.h
        OrderUI.cpp
        OrderUI.h
        CustomerUI.cpp
        CustomerUI.h
        EmployeeUI.cpp
        EmployeeUI.h
        FinalUI.cpp
        FinalUI.h
        adminUI.cpp
        adminUI.h)
