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
                     ../src/utils.h
                     ../src/utils.cpp
                     ../src/functions.h
                     ../src/functions.cpp)

add_executable(lab4_test lab4_test.cpp
                        ../src/parent.h
                        ../src/parent.cpp
                        ../src/utils.h
                        ../src/utils.cpp)

target_link_libraries(lab4_test PRIVATE GTest::GTest)
target_include_directories(lab4_test PRIVATE)

add_test(lab4_test lab4_test)

project(tests)