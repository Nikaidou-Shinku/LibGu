cmake_minimum_required(VERSION 3.5)
project(LibGu VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(3rdparty/catch2 EXCLUDE_FROM_ALL)
add_subdirectory(3rdparty/fmt EXCLUDE_FROM_ALL)
add_subdirectory(src)
add_subdirectory(tests)
