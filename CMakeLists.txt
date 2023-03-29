cmake_minimum_required(VERSION 3.5)

project(todo_console LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(todo_console main.cpp)

set(SOURCES main.cpp mlist.cpp ${todo_console}/mlist.hpp )
target_include_directories(todo_console
    PUBLIC
    "${PROJECT_SOURCE_DIR}/headers/")





