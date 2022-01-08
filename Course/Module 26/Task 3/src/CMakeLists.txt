cmake_minimum_required(VERSION 3.21)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(Task_3 main.cpp Monitor.cpp ${INCLUDE_DIR}/Monitor.h Window.cpp ${INCLUDE_DIR}/Window.h)
target_include_directories(Task_3 PUBLIC ${INCLUDE_DIR})