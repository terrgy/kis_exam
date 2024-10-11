cmake_minimum_required(VERSION 3.28)
project(kis_exam)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(kis_exam src/main.cpp
        src/App.cpp
        include/App.h
        src/Task.cpp
        include/Task.h
        src/Trie.cpp
        include/Trie.h)

include_directories(include)