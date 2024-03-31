cmake_minimum_required(VERSION 3.15)

# https://cmake.org/cmake/help/latest/command/project.html
project(example-dynlib VERSION 0.1.0 
    DESCRIPTION "Example x-platform dynamic library to use as template"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.cxx")

configure_file("${INCLUDE_DIR}/dynlibconfig.h.in" "${PROJECT_BINARY_DIR}/include/dynlibconfig.h")

add_library(example-dynlib SHARED ${SOURCE_FILES})

target_include_directories(example-dynlib PUBLIC "${PROJECT_BINARY_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/include")