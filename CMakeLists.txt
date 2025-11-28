cmake_minimum_required(VERSION 3.20)
project(mon_projet_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(mon_projet_cpp
        src/main.cpp
        src/DynamicArray.cpp
        src/DynamicArray.h++
)
