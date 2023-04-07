cmake_minimum_required(VERSION 3.0.0)
project(LAB5_2 VERSION 0.1.0)

add_library(math1 SHARED math1.cpp)
add_library(math2 SHARED math2.cpp)

add_executable(prog2 main.cpp
                     lab5_2.h
                     lab5_2.cpp)

target_link_libraries(prog2 math1 math2)