cmake_minimum_required(VERSION 3.27)
project(Project1_DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_DA
        Graph.h
        T1/App.cpp
        T2/BSM.cpp
        T3/RSF.cpp
        main.cpp
)