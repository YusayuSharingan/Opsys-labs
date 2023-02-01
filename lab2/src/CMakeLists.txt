cmake_minimum_required(VERSION 3.16)

project(lab2)

add_executable(child child.cpp
                     functions.h
                     functions.cpp)

add_executable(lab2 main.cpp
                    parent.h
                    parent.cpp
                    checkers.h
                    checkers.cpp)
