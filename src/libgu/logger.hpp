#ifndef __LIBGU_LOGGER_HEADER
#define __LIBGU_LOGGER_HEADER

#include "fmt/color.h"
#include <string>

namespace gu {

namespace details {

using String = std::string;

class Logger {
  private:
    Logger() { };
    static Logger *pInstance;

    String getBaseInfo(const char*) const;

  public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* get();

    template<typename... Args>
    Logger* log(const char *location, fmt::format_string<Args...> _format, Args&&... args) {
        String base = getBaseInfo(location);
        String msg = fmt::format(_format, args...);
        fmt::print("{} [Info] {}\n", base, msg);
        return this;
    }
    
    template<typename... Args>
    Logger* warn(const char *location, fmt::format_string<Args...> _format, Args&&... args) {
        String base = getBaseInfo(location);
        String msg = fmt::format(_format, args...);
        fmt::print(fg(fmt::color::yellow), "{} [Warn] {}\n", base, msg);
        return this;
    }

    template<typename... Args>
    Logger* error(const char *location, fmt::format_string<Args...> _format, Args&&... args) {
        String base = getBaseInfo(location);
        String msg = fmt::format(_format, args...);
        fmt::print(fg(fmt::color::red), "{} [Error] {}\n", base, msg);
        return this;
    }
};

} // end namespace detail

} // end namespace gu

#define __GLOG_S1(x) #x
#define __GLOG_S2(x) __GLOG_S1(x)
#define __GLOG_LOCATION __FILE__ ": " __GLOG_S2(__LINE__)

#define GLOG(_format, ...)           \
    do {                             \
        gu::details::Logger::get()   \
            ->log(__GLOG_LOCATION,   \
                FMT_STRING(_format), \
                ##__VA_ARGS__);      \
    } while (false)

#define GWRN(_format, ...)           \
    do {                             \
        gu::details::Logger::get()   \
            ->warn(__GLOG_LOCATION,  \
                FMT_STRING(_format), \
                ##__VA_ARGS__);      \
    } while (false)

#define GERR(_format, ...)           \
    do {                             \
        gu::details::Logger::get()   \
            ->error(__GLOG_LOCATION, \
                FMT_STRING(_format), \
                ##__VA_ARGS__);      \
    } while (false)

#endif
