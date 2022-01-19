add_executable(random_test test.cpp)

target_link_libraries(random_test PRIVATE gu_test)
target_link_libraries(random_test PRIVATE gu)

add_test(random random_test)
