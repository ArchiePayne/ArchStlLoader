# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(ArchStlLoader)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

file(GLOB SOURCES
    src/ArchStlLoader.cpp
    src/allmain.cpp
    src/pch.cpp
)

set(HEADERS
    src/ArchStlLoader.h
    src/framework.h
    src/pch.h
)

# Create a shared library (DLL)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Define the macro for exporting/importing functions for the DLL
target_compile_definitions(${PROJECT_NAME} PRIVATE "ARCHSTLLOADER_EXPORTS")

# Include directories (add path to the src/ directory)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)