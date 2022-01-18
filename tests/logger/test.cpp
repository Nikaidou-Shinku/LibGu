#include "catch.hpp"

#include "libgu/logger.hpp"
#include <string>

TEST_CASE("test logger error") {
    GERR("Some error!");
}

TEST_CASE("test logger warn") {
    GWRN("Some warn!");
}

TEST_CASE("test logger log") {
    GLOG("Some log...");
}

TEST_CASE("test logger mixed") {
    GLOG("1 + 2 = {}", 3);
    GERR("6 / 5 = {:.2f}", static_cast<double>(6) / 5);
    GWRN("3 * 5 = {:s}", std::string("15"));
}
