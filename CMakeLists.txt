cmake_minimum_required(VERSION 3.27)
project(MyStuff)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyStuff
        main.cpp
        implementation/allocator.h
        implementation/linked_list.h
        implementation/exceptions.h
)
