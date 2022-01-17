#ifndef __LIBGU_HELLO_HEADER
#define __LIBGU_HELLO_HEADER

#include "fmt/core.h"
#include <string>

namespace gu {

class Hello {
  private:
    std::string helloMessage;

  public:
    Hello(): helloMessage("Hello, world!") { }

    size_t print() const {
        fmt::print("{}\n", helloMessage);
        return helloMessage.length();
    }
};

} // end namespace gu

#endif
