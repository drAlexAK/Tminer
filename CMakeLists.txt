cmake_minimum_required(VERSION 3.22)
project(TMiner)

set(CMAKE_CXX_STANDARD 17)

add_executable(TMiner main.cpp)
add_executable(console Console.cpp)
add_executable(print Print.cpp)
add_executable(font Font.cpp)