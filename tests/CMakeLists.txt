add_library(gu_test STATIC EXCLUDE_FROM_ALL main.cpp)

target_link_libraries(gu_test PUBLIC catch2)

add_subdirectory(hello)
add_subdirectory(logger)
add_subdirectory(random)
