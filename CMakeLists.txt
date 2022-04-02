cmake_minimum_required(VERSION 3.20)
project(SwordForOffer)

set(CMAKE_CXX_STANDARD 14)
#ADD_SUBDIRECTORY(Chapter3)

include_directories(cpputil)
include_directories(Chapter2)
add_executable(SwordForOffer main.cpp )
