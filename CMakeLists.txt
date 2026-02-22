cmake_minimum_required(VERSION 3.10)
project(VirtualRTOS)

set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# List all source files
add_executable(RTOS
    src/main.cpp
    src/kernel/scheduler.cpp
    src/kernel/semaphore.cpp
    src/profiler/profiler.cpp
)
