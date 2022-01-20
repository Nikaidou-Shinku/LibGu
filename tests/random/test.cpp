#include "catch.hpp"
#include <vector>
#include <string>
#include <algorithm>

#include "libgu/random.hpp"
#include "libgu/logger.hpp"

TEST_CASE("test random integer") {
  const size_t n = 10, l = 10000, p = 10;
  GLOG("Random integet tests");
  for (size_t i = 0; i < p; i ++) {
    size_t sum = 0, squareSum = 0;
    for (size_t j = 0; j < l; j ++) {
      size_t x = gu::randn(n);
      REQUIRE(x >= 0);
      REQUIRE(x < n);
      sum += x; squareSum += x * x;
    }
    double squdiff = static_cast<double>(l * squareSum - sum * sum) / l / l;
    GLOG("TEST {:2d} | Square Difference: {:6f}", i, squdiff);
    REQUIRE(squdiff > static_cast<double>(n * n) / 12.5);
    REQUIRE(squdiff < static_cast<double>(n * n) / 10);
  }
}

TEST_CASE("test random float") {
  const size_t l = 10000, p = 10;
  const double n = 100;
  GLOG("Random float tests");
  for (size_t i = 0; i < p; i ++) {
    double sum = 0, squareSum = 0;
    for (size_t j = 0; j < l; j ++) {
      double x = gu::randf(n);
      REQUIRE(x >= 0);
      REQUIRE(x < n);
      sum += x; squareSum += x * x;
    }
    double squdiff = static_cast<double>(l * squareSum - sum * sum) / l / l;
    GLOG("TEST {:2d} | Square Difference: {:6f}", i, squdiff);
    REQUIRE(squdiff > n * n / 12.5);
    REQUIRE(squdiff < n * n / 10);
  }
}

TEST_CASE("test random string") {
  const size_t n = 100;
  const std::string str = "0222333333";
  const size_t t = 10;
  GLOG("Random string tests");
  for (size_t i = 1; i <= t; i ++){
    std::string x = gu::rands(n, str);
    GLOG("{}", x);
  }
}
