cmake_minimum_required(VERSION 3.24)
project(data_structures_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_structures_cpp main.cpp)
add_executable(vector-test main.cpp vector.h vector.cpp)
