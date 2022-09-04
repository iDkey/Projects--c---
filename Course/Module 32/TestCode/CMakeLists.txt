cmake_minimum_required(VERSION 3.23)
project(TestCode)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(TestCode main.cpp)

target_link_libraries(TestCode PRIVATE nlohmann_json::nlohmann_json)