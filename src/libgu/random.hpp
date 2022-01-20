#ifndef __LIBGU_RANDOM_HEADER
#define __LIBGU_RANDOM_HEADER

#include <random>
#include <type_traits>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

namespace gu {
    
namespace random {

class RandomMachine {
  private:
    std::default_random_engine e;
    RandomMachine() { e.seed(time(0)); };
    static RandomMachine *rndInstance;

  public:
    RandomMachine(const RandomMachine&) = delete;
    RandomMachine& operator=(const RandomMachine&) = delete;

    static RandomMachine* get();

    template<class T, class = std::enable_if_t<std::is_integral<T>::value>>
    T randn(T L, T R) {
      std::uniform_int_distribution<T> u(L, R);
      return u(e);
    }

    template<class T, class = std::enable_if_t<std::is_integral<T>::value>>
    T randn(T n) {
      std::uniform_int_distribution<T> u(0, n-1);
      return u(e);
    }

    template<class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
    T randf(T L, T R) {
      std::uniform_real_distribution<T> u(L, R);
      return u(e);
    }

    template<class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
    T randf(T n) {
      std::uniform_real_distribution<T> u(0, n);
      return u(e);
    }

    std::string rands(size_t len, std::string alphabet) {
      std::string ret("");
      for (size_t i = 0; i < len; i ++)
        ret += alphabet[randn(alphabet.size())];
      return ret;
    }

    template<class T, class = std::enable_if_t<std::is_integral<T>::value>>
    std::vector<size_t> randpn(size_t len, std::vector<T> prob) {
      std::vector<size_t> ret(0);
      const size_t probLen = prob.size();
      for (size_t i = 1; i < probLen; i ++)
        prob[i] += prob[i-1];
      const T cnt = prob.back();
      for (size_t i = 0; i < len; i ++)
        ret.push_back(static_cast<size_t>(lower_bound(prob.begin(), prob.end(), randn(cnt)) - prob.begin()));
      return ret;
    }

    template<class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
    std::vector<size_t> randpf(size_t len, std::vector<T> prob) {
      std::vector<size_t> ret(0);
      const size_t probLen = prob.size();
      for (size_t i = 1; i < probLen; i ++)
        prob[i] += prob[i-1];
      const T cnt = prob.back();
      for (size_t i = 0; i < len; i ++)
        ret.push_back(static_cast<size_t>(lower_bound(prob.begin(), prob.end(), randf(cnt)) - prob.begin()));
      return ret;
    }
};

} // end namespace random

template<class T, class = std::enable_if_t<std::is_integral<T>::value>>
static T randn(T L, T R) {
  return gu::random::RandomMachine::get() -> randn(L, R);
}

template<class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
static T randf(T L, T R) {
  return gu::random::RandomMachine::get() -> randf(L, R);
}

template<class T, class = std::enable_if_t<std::is_integral<T>::value>>
static T randn(T n) {
  return gu::random::RandomMachine::get() -> randn(n);
}

template<class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
static T randf(T n) {
  return gu::random::RandomMachine::get() -> randf(n);
}

static std::string rands(size_t len, std::string alphabet) {
  return gu::random::RandomMachine::get() -> rands(len, alphabet);
}

template<class T, class = std::enable_if_t<std::is_integral<T>::value>>
std::vector<size_t> randpn(size_t len, std::vector<T> prob){
  return gu::random::RandomMachine::get() -> randpn(len, prob);
}

template<class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
std::vector<size_t> randpf(size_t len, std::vector<T> prob){
  return gu::random::RandomMachine::get() -> randpf(len, prob);
}

} // end namespace gu

#endif
