cmake_minimum_required(VERSION 3.30)
project(NTaskManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(NTaskManager main.cpp
        includes/Task.h++
        src/Task.cpp
        src/LegacyTask.cpp
        includes/LegacyTask.h++
        includes/Utils.h++
)
