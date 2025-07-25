cmake_minimum_required(VERSION 3.22)
cmake_policy(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GBFr)

# grab src and include
FILE(GLOB SRC_FILES "src/*")

message(STATUS "building src files...")
add_library(src ${SRC_FILES})
target_include_directories(src PUBLIC include)

add_executable(GBFr main.cpp)
target_link_libraries(GBFr src)
