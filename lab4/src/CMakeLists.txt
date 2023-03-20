cmake_minimum_required(VERSION 3.16)

project(lab3)


set(CMAKE_CXX_STANDARD 17)

add_executable(child ./child.cpp
                     ./functions.h
                     ./functions.cpp
                     ./utils.h
                     ./utils.cpp)
                        
                     
add_executable(lab4_test ./main.cpp
                        ./parent.h
                        ./parent.cpp
                        ./utils.h
                        ./utils.cpp)



