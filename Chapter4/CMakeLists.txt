project(chapter4)
cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)
aux_source_directory(. SRC_LIST)
include_directories(../cpputil/container)


MESSAGE(STATUS "this source dir" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "this binary dir" ${PROJECT_BINARY_DIR})

add_executable(chapter4 ${SRC_LIST} ../cpputil/container/ContainersUtil.h ../cpputil/container/ContainersUtil.cpp )