cmake_minimum_required(VERSION 3.21)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG c8d33915dbd88ad6c92b258869b03aba06587ff9)
FetchContent_MakeAvailable(cpr)

add_executable(Task_2 main.cpp)

target_link_libraries(Task_2 PRIVATE cpr::cpr)