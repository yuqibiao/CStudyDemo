cmake_minimum_required(VERSION 3.6)
project(CStudyDemo)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES exercises/HanioTest.c)
add_executable(CStudyDemo ${SOURCE_FILES})