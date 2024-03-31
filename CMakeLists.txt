cmake_minimum_required(VERSION 3.23.2)
project(Project1DataSetSmall)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1DataSetSmall
        Graph.h
        Management.cpp
        Management.h
        MutablePriorityQueue.h
        UFDS.cpp
        UFDS.h
        main.cpp)
