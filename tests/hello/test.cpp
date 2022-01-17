#include "catch.hpp"

#include "libgu/hello.hpp"

TEST_CASE("test environment") {
    gu::Hello test;
    REQUIRE(test.print() == 13);
}
