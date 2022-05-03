cmake_minimum_required(VERSION 3.22)
project(unt)

set(CMAKE_CXX_STANDARD 17)

add_executable(unt main.cpp Font.cpp Font.h Console.cpp Console.h Print.cpp Print.h Objects.h Definitions.h Definitions.cpp)
