// ʕ •ᴥ•ʔ Paths - runtime.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "runtime.hpp"
#include "detect.hpp"
#include "strings.hpp"
#include "paths.hpp"
#include <string>

#if PLATFORM_DETECTED_OS == PLATFORM_LINUX

#include <linux/limits.h>
#include <unistd.h>

std::string paths::filename() {
    char    result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return result;
}

#elif PLATFORM_DETECTED_OS == PLATFORM_DARWIN

#include <mach-o/dyld.h>

std::string paths::filename() {
    auto bufsize = static_cast<uint32_t>(PATH_MAX);
    char buf[bufsize];

    if (_NSGetExecutablePath(buf, &bufsize) == -1) {
        throw std::length_error(
            "Filename exceeds maximum path length: " + std::to_string(PATH_MAX)
        );
    }

    return realpath(buf, NULL);
}

#elif PLATFORMS_DETECTED_OS == PLATFORM_WINDOWS

std::string paths::filename() {
    return "";
}

#elif PLATFORMS_DETECTED_OS == PLATFORM_BSD

std::string paths::filename() {
    return "";
}

#elif PLATFORMS_DETECTED_OS == PLATFORM_SOLARIS

std::string paths::filename() {
    return "";
}

#elif PLATFORMS_DETECTED_OS == PLATFORM_IOS

std::string paths::filename() {
    return "";
}

#elif PLATFORMS_DETECTED_OS == PLATFORM_ANDROID

std::string paths::filename() {
    return "";
}

#endif

std::string paths::dirname() {
    return tail(filename());
}
