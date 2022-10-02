// ʕ •ᴥ•ʔ Paths - runtime.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "runtime.hpp"
#include "components.hpp"
#include "detect.hpp"
#include "inspect.hpp"
#include "segments.hpp"
#include <string>

#if PLATFORM_DETECTED_OS == PLATFORM_LINUX

#include <linux/limits.h>
#include <unistd.h>

std::string paths::filename() {
    char buffer[PATH_MAX];
    readlink("/proc/self/exe", buffer, PATH_MAX);
    return buffer;
}

#elif (                                                                        \
    PLATFORM_DETECTED_OS == PLATFORM_DARWIN ||                                 \
    PLATFORM_DETECTED_OS == PLATFORM_IOS                                       \
)

#include <mach-o/dyld.h>
#include <stdexcept>

std::string paths::filename() {
    auto bufsize = static_cast<uint32_t>(PATH_MAX);

    char buffer[bufsize];

    if (_NSGetExecutablePath(buffer, &bufsize) == -1) {
        throw std::length_error(
            "Filename exceeds maximum path length: " + std::to_string(PATH_MAX)
        );
    }

    return realpath(buffer, NULL);
}

#elif PLATFORM_DETECTED_OS == PLATFORM_WINDOWS

#include <stdexcept>
#include <windows.h>

std::string paths::filename() {
    wchar_t buffer[MAX_PATH];
    auto    size = GetModuleFileNameW(NULL, buffer, MAX_PATH);

    if (size > MAX_PATH + 1) {
        throw std::length_error(
            "Filename exceeds maximum path length: " + std::to_string(MAX_PATH)
        );
    }

    std::wstring ws(buffer);

    return std::string(ws.begin(), ws.end());
}

#elif PLATFORM_DETECTED_OS == PLATFORM_BSD

std::string paths::filename() {
    return "";
}

#elif PLATFORM_DETECTED_OS == PLATFORM_SOLARIS

std::string paths::filename() {
    return "";
}

#elif PLATFORM_DETECTED_OS == PLATFORM_ANDROID

std::string paths::filename() {
    char buffer[PATH_MAX];
    readlink("/proc/self/maps", buffer, PATH_MAX);
    // realpath(path, buffer);
    // munmap(begin, offset);
    // fclose(maps);
    return buffer;
}

#endif

std::string paths::dirname() {
    return tail(filename());
}

std::string paths::abspath(const std::string &path) {
    return absolute(path) ? path : resolve({dirname(), path});
}
