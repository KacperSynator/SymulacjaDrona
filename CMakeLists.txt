cmake_minimum_required(VERSION 3.2)

project(SymulacjaDrona)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC "src/*")

find_library(pthread REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} pthread)
