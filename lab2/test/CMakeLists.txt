cmake_minimum_required(VERSION 3.16.3)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


set(CMAKE_CXX_STANDARD 17)


# LAB 2 tests

add_executable(child ../src/child.cpp
                     ../src/functions.h
                     ../src/functions.cpp)

add_executable(lab2_test l2_test.cpp
                    ../src/parent.h
                    ../src/parent.cpp
                    ../src/checkers.h
                    ../src/checkers.cpp)

target_link_libraries(lab2_test PRIVATE GTest::GTest)
target_include_directories(lab2_test PRIVATE)

add_test(lab2_test lab2_test)

project(tests)