add_executable(hello_test test.cpp)

target_link_libraries(hello_test PRIVATE gu_test)
target_link_libraries(hello_test PRIVATE gu)

add_test(hello hello_test)
