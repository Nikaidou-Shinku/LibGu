add_executable(logger_test test.cpp)

target_link_libraries(logger_test PRIVATE gu_test)
target_link_libraries(logger_test PRIVATE gu)

add_test(logger logger_test)
