#ifndef __LIBGU_RANDOM_HEADER
#define __LIBGU_RANDOM_HEADER

#include <random>
#include <type_traits>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>

namespace gu {
    
namespace details {

class RandomMachine {
  private:
    std::default_random_engine e;
    RandomMachine() { e.seed(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())); };
    static RandomMachine *rndInstance;

  public:
    RandomMachine(const RandomMachine&) = delete;
    RandomMachine& operator=(const RandomMachine&) = delete;

    static RandomMachine* get();

    template<typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
    T randn(T L, T R) {
      std::uniform_int_distribution<T> u(L, R);
      return u(e);
    }

    template<typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
    T randn(T n) {
      std::uniform_int_distribution<T> u(0, n-1);
      return u(e);
    }

    template<typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
    T randf(T L, T R) {
      std::uniform_real_distribution<T> u(L, R);
      return u(e);
    }

    template<typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
    T randf(T n) {
      std::uniform_real_distribution<T> u(0, n);
      return u(e);
    }

    std::string rands(size_t len, std::string alphabet) {
      std::string ret;
      for (size_t i = 0; i < len; i ++)
        ret += alphabet[randn(alphabet.size())];
      return ret;
    }
};

} // end namespace details

template<typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
static inline T randn(T L, T R) {
  return gu::details::RandomMachine::get() -> randn(L, R);
}

template<typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
static inline T randf(T L, T R) {
  return gu::details::RandomMachine::get() -> randf(L, R);
}

template<typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
static inline T randn(T n) {
  return gu::details::RandomMachine::get() -> randn(n);
}

template<typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
static inline T randf(T n) {
  return gu::details::RandomMachine::get() -> randf(n);
}

static inline std::string rands(size_t len, std::string alphabet) {
  return gu::details::RandomMachine::get() -> rands(len, alphabet);
}

} // end namespace gu

#endif
