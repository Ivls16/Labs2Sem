cmake_minimum_required(VERSION 3.29)
project(Task2)

set(CMAKE_CXX_STANDARD 20)

add_library(StringLib SHARED String.cpp)
add_executable(Task2 main.cpp)
target_link_libraries(Task2 StringLib)
