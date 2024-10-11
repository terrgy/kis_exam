cmake_minimum_required(VERSION 3.28)
project(kis_exam)

set(CMAKE_CXX_STANDARD 23)

add_executable(kis_exam src/main.cpp
        src/App.cpp
        include/App.h
        src/Task.cpp
        include/Task.h)

include_directories(include)