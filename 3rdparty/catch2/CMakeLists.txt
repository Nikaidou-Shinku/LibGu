add_library(catch2 catch.hpp)

set_target_properties(catch2 PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(catch2 INTERFACE
    "${PROJECT_SOURCE_DIR}/3rdparty/catch2")
