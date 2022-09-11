cmake_minimum_required(VERSION 3.23)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(LoginAndRegistrationSystem main.cpp ${INCLUDE_DIR}/ValidateData.h ValidateData.cpp)
target_include_directories(LoginAndRegistrationSystem PUBLIC ${INCLUDE_DIR})