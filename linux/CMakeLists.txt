cmake_minimum_required(VERSION 3.5)

project(linux C)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

add_executable(minitee minitee.c)
