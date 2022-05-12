cmake_minimum_required(VERSION 3.10.2)

project(Software1)

#comment
include_directories(include)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
file(GLOB SOURCES "src/*.cpp")
add_executable(Software1.bin ${SOURCES})
