cmake_minimum_required(VERSION 3.23)
project(crypto2)

set(CMAKE_CXX_STANDARD 23)

add_executable(crypto2 main.cpp encr.cpp decr.cpp header.hpp)
