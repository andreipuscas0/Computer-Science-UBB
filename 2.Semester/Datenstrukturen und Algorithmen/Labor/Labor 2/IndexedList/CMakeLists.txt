cmake_minimum_required(VERSION 3.27)
project(Labor_2__IndexedList_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Labor_2__IndexedList_
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IndexedList.cpp
        IndexedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
