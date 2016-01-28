cmake_minimum_required(VERSION 3.2)
project(heightOfBinaryTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)

add_executable(heightOfBinaryTree ${SOURCE_FILES})

target_link_libraries(heightOfBinaryTree myBinaryTree)