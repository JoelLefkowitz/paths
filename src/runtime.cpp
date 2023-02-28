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
    readlink("/proc/self/exe", buffer, PATH_MAX);
    return buffer;
}

#elif PLATFORM_OS == PLATFORM_OS_SOLARIS

std::string paths::filepath() {
    return "";
}

#elif PLATFORM_OS == PLATFORM_OS_WINDOWS

#include <stdexcept>
#include <windows.h>

std::string paths::filepath() {
    wchar_t buffer[MAX_PATH];
    auto    size = GetModuleFilepathW(NULL, buffer, MAX_PATH);

    if (size > MAX_PATH + 1) {
        throw std::length_error(
            "Filepath exceeds maximum path length: " + std::to_string(MAX_PATH)
        );
    }

    std::wstring ws(buffer);

    return std::string(ws.begin(), ws.end());
}

#elif PLATFORM_OS == PLATFORM_OS_BSD

std::string paths::filepath() {
    return "";
}

#elif (PLATFORM_OS == PLATFORM_OS_MACOS) ||                                    \
    (PLATFORM_OS == PLATFORM_OS_IOS) ||                                        \
    (PLATFORM_OS == PLATFORM_OS_WATCHOS) || (PLATFORM_OS == PLATFORM_OS_TVOS)

#include <mach-o/dyld.h>
#include <stdexcept>

const size_t PATH_MAX = 1024;

std::string paths::filepath() {
    auto bufsize = static_cast<uint32_t>(PATH_MAX);

    char buffer[bufsize];

    if (_NSGetExecutablePath(buffer, &bufsize) == -1) {
        throw std::length_error(
            "Filepath exceeds maximum path length: " + std::to_string(PATH_MAX)
        );
    }

    return realpath(buffer, NULL);
}

#elif PLATFORM_OS == PLATFORM_OS_ANDROID

std::string paths::filepath() {
    char buffer[PATH_MAX];
    readlink("/proc/self/maps", buffer, PATH_MAX);
    // realpath(path, buffer);
    // munmap(begin, offset);
    // fclose(maps);
    return buffer;
}

#else

#error "Unrecognised OS, could not define paths::filepath()"

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
