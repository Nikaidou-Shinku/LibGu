add_library(gu STATIC libgu/hello.hpp)

set_target_properties(gu PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(gu INTERFACE fmt::fmt)

target_include_directories(gu INTERFACE
    "${PROJECT_SOURCE_DIR}/src")
