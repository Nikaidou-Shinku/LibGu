add_library(gu STATIC
  libgu/logger.cpp)

target_link_libraries(gu PUBLIC fmt::fmt)

target_include_directories(gu PUBLIC
  "${PROJECT_SOURCE_DIR}/src")
