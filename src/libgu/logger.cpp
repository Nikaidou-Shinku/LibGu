#include "libgu/logger.hpp"

#include "fmt/chrono.h"
#include <chrono>

namespace gu {

namespace details {

Logger *Logger::pInstance = nullptr;

String Logger::getBaseInfo(const char *location) const {
    auto nowTime = std::chrono::system_clock::now();
    size_t size = strlen(location);
    const char *p = location + size;
    const char *base = location;
    while (p > location) {
        char c = *--p;
        if (c == '/' || c == '\\') {
            base = p + 1;
            break;
        }
    }
    return fmt::format("{} ({})", nowTime, base);
}

Logger* Logger::get() {
    if (pInstance == nullptr)
        pInstance = new Logger;
    return pInstance;
}

} // end namespace details

} // end namespace gu
