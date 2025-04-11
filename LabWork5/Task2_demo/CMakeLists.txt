cmake_minimum_required(VERSION 3.29)
project(Task2_demo)

set(CMAKE_CXX_STANDARD 20)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(Task2_demo main.cpp)
target_link_libraries(Task2_demo StringLib)
set(CMAKE_BUILD_RPATH ${CMAKE_SOURCE_DIR}/lib)
