cmake_minimum_required(VERSION 3.26)
project(BTrees)

set(CMAKE_CXX_STANDARD 17)

add_executable(BTrees main.cpp
        BTree.cpp
        BTree.h
        BTree_Array_Functions.cpp
        BTree_Array_Functions.h
        Node.cpp
        Node.h)
