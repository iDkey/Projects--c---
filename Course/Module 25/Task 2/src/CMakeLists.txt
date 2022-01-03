cmake_minimum_required(VERSION 3.21)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Task_2 main.cpp ${INCLUDE_DIR}/cpu.h ${INCLUDE_DIR}/disk.h ${INCLUDE_DIR}/gpu.h ${INCLUDE_DIR}/kbd.h ${INCLUDE_DIR}/ram.h Cpu.cpp Disk.cpp Gpu.cpp Kbd.cpp Ram.cpp)
target_include_directories(Task_2 PUBLIC ${INCLUDE_DIR})