cmake_minimum_required(VERSION 3.20)

project(TaskManager LANGUAGES CXX)

add_subdirectory(src/task)

add_executable(TaskManager
    src/main.cpp
)

target_compile_features(TaskManager PRIVATE cxx_std_20)
