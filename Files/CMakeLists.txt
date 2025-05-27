cmake_minimum_required(VERSION 3.10)
project(Files)

set(CMAKE_CXX_STANDARD 17)

add_executable(Files main.cpp
        User.cpp
        Book.cpp
        UserList.cpp
        BookList.cpp)
