cmake_minimum_required(VERSION 3.16)
project(cmake_project VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Main library
add_library(mylib src/mylib.cpp)

# Main executable
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE mylib)

# Testing
enable_testing()
add_subdirectory(tests)
