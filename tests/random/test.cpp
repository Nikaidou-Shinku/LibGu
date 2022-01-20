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
    size_t sm = 0, squsm = 0;
    for (size_t j = 0; j < l; j ++){
      size_t x = gu::randn(n);
      REQUIRE(x >= 0); REQUIRE(x < n);
      sm += x; squsm += x * x;
    }
    double_t squdiff = static_cast<double_t>(l * squsm - sm * sm) / l / l;
    GLOG("TEST {:2d} | Square Difference: {:6f}", i, squdiff);
    REQUIRE(squdiff > static_cast<double_t>(n * n) / 12.5);
    REQUIRE(squdiff < static_cast<double_t>(n * n) / 10);
  }
}

TEST_CASE("test random float") {
  const size_t l = 10000, p = 10;
  const double_t n = 100;
  GLOG("Random float tests");
  for (size_t i = 0; i < p; i ++) {
    double_t sm = 0, squsm = 0;
    for (size_t j = 0; j < l; j ++){
      double_t x = gu::randf(n);
      REQUIRE(x >= 0); REQUIRE(x < n);
      sm += x; squsm += x * x;
    }
    double_t squdiff = static_cast<double_t>(l * squsm - sm * sm) / l / l;
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

TEST_CASE("test random probability") {
  const size_t n = 100, t = 4;
  const std::vector<double_t> prob{0.1, 0, 0.3, 0.6};
  std::vector<size_t> v(t);
  std::vector<size_t> res = gu::randp(n, prob);
  for (size_t i = 0; i < n; i ++)
    ++ v[res[i]];
  GLOG("Counts of a list with {} items:", n, n);
  for (size_t i = 0; i < t; i ++)
    GLOG("{:2d} [PROB {:4f}]: {}", i, prob[i], v[i]);
}
