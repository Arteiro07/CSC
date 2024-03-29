###########################################################################################################################################################

# Built by Gonçalo Tomas (87009) and Manuel Ruivo (87061)
# Instituto Superior Tecnico, Univ. Lisboa


# What is file list?
#
# File that contains a set of directives and instructions describing the project's source files and targets (executable, library, or both).
#
# Find more about CMake here -> https://cmake.org/cmake/help/latest/guide/tutorial/index.html

###########################################################################################################################################################

# WARNING - The name of this file CAN'T BE CHANGED.
# WARNING - This file may need changes in order to serve your purpose

# CMAKE VERSION_
cmake_minimum_required(VERSION 3.12) 

# PROJECT NAME [OPTIONAL]:
project(CLIENT)

# FIND SEAL VERSION:
find_package(SEAL 3.6.0 EXACT REQUIRED)


# TO SET DIFERENT DIRECTORY (e.g. yourdir) [OPTIONAL, BY DEFAULT: PROJECT DIRECTORY]:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/execs)

# CHOOSE EXECUTABLE NAME (e.g exec)
add_executable(run)

# ADD ALL SOURCE FILES TO BE COMPILED (e.g. exec.cpp)
target_sources(run 
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/client.cpp
            ${CMAKE_CURRENT_LIST_DIR}/create.cpp
            ${CMAKE_CURRENT_LIST_DIR}/insert.cpp
            ${CMAKE_CURRENT_LIST_DIR}/query.cpp
            ${CMAKE_CURRENT_LIST_DIR}/sum.cpp
            ${CMAKE_CURRENT_LIST_DIR}/cert.cpp
    	)

# PRIVATE FLAG MAY BE CHANGED FOR PUBLIC OR INTERFACE
# SEE: https://cmake.org/pipermail/cmake/2016-May/063400.html


# LINK SEAL
target_link_libraries(run SEAL::seal)
