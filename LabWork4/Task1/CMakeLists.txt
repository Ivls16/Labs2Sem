cmake_minimum_required(VERSION 3.29)
project(Task1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task1 main.cpp
        merge_sort.cpp
        quick_sort.cpp
        heap.cpp
        heap_sort.cpp
        binsearch.cpp
        binpow.cpp
        interpolation_sort.cpp)
