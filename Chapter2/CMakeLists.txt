project(chapter2)
cmake_minimum_required(VERSION 3.20)
aux_source_directory(. SRC_LIST)
add_executable(chapter2 ${SRC_LIST})