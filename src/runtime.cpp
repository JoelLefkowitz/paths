// ʕ •ᴥ•ʔ Paths - runtime.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "runtime.hpp"
#include "components.hpp"
#include "detect.hpp"
#include <string>

#if PLATFORM_OS == PLATFORM_OS_LINUX

#include <linux/limits.h>
#include <unistd.h>

std::string paths::filepath() {
    char buffer[PATH_MAX];

    ssize_t size = readlink("/proc/self/exe", buffer, PATH_MAX);

    return std::string(buffer).substr(0, size);
}

#elif PLATFORM_OS == PLATFORM_OS_WINDOWS

#include <stdexcept>
#include <windows.h>

std::string paths::filepath() {
    wchar_t buffer[MAX_PATH];

    auto size = GetModuleFileNameW(NULL, buffer, MAX_PATH);

    if (size > MAX_PATH + 1) {
        throw std::length_error("Filepath exceeds maximum path length: " + std::to_string(MAX_PATH));
    }

    std::wstring ws(buffer);
    return std::string(ws.begin(), ws.end());
}

#elif (PLATFORM_OS == PLATFORM_OS_MACOS) || (PLATFORM_OS == PLATFORM_OS_IOS) ||                                        \
    (PLATFORM_OS == PLATFORM_OS_WATCHOS) || (PLATFORM_OS == PLATFORM_OS_TVOS)

#include <mach-o/dyld.h>

// cppclean-disable-next-line
#include <stdexcept>

std::string paths::filepath() {
    uint32_t size = PATH_MAX;

    char buffer[PATH_MAX];

    if (_NSGetExecutablePath(buffer, &size) == -1) {
        throw std::length_error("Filepath exceeds maximum path length: " + std::to_string(PATH_MAX));
    }

    return realpath(buffer, NULL);
}

#else

#error "Unsupported OS, could not define paths::filepath()"

#endif

std::string paths::filename() {
    return head(filepath());
}

std::string paths::dirpath() {
    return tail(filepath());
}

std::string paths::dirname() {
    return head(tail(filepath()));
}
