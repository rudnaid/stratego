cmake_minimum_required(VERSION 3.28)

project(stratego)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include/core/
        include/ui/
        include/rules
        include/util
)

add_subdirectory(source)
