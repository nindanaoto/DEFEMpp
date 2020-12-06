cmake_minimum_required(VERSION 3.9)
project(tfhe++ CXX)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-march=native -O3 -std=c++20 -g")

add_subdirectory(test)