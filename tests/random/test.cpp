#include "catch.hpp"
#include <vector>
#include <string>

#include "libgu/random.hpp"
#include "libgu/logger.hpp"

TEST_CASE("test random integer") {
  const size_t n = 10, t = 10000;
  std::vector<size_t> v(n);
  for (size_t i = 0; i < t; i ++)
    ++ v[randn(n)];
  GSUC("Counts of {} randoms in [0, {})", t, n);
  for (size_t i = 0; i < n; i ++)
    GLOG("{:2d}: {}", i, v[i]);
}

TEST_CASE("test random float") {
  const double_t n = 15.0;
  const size_t t = 10;
  GSUC("{} randoms in [0, {:.3f})", t, n);
  for (size_t i = 1; i <= t; i ++)
    GLOG("{:2d}: {:6f}", i, randf(n));
}

TEST_CASE("test random string") {
  const size_t n = 100;
  const std::string str = "00001";
  const size_t t = 10;
  GSUC("String of length {}, alphabet \"{}\"", n, str);
  for (size_t i = 1; i <= t; i ++)
    GLOG("Test {:2d}: {}", i, rands(n, str));
}

TEST_CASE("test random probability") {
  const size_t n = 100, t = 4;
  const std::vector<double> prob{0.1, 0, 0.3, 0.6};
  std::vector<size_t> v(4);
  std::vector<size_t> res = randp(n, prob);
  for (size_t i = 0; i < n; i ++)
    ++ v[res[i]];
  GSUC("Counts of a list with {} items:", n, n);
  for (size_t i = 0; i < t; i ++)
    GLOG("{:2d} [PROB {:4f}]: {}", i, prob[i], v[i]);
}