cmake_minimum_required(VERSION 3.2)
project(BinaryTreeEx1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(BinaryTreeEx1 ${SOURCE_FILES} testlib.h testlib.c)

target_link_libraries(BinaryTreeEx1 myBinaryTree)