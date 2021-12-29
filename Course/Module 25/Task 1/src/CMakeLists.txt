cmake_minimum_required(VERSION 3.21)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Task_1 main.cpp ${INCLUDE_DIR}/functions.h)
target_include_directories(Task_1 PUBLIC ${INCLUDE_DIR})