#include "realtime.hpp"
#include "components.hpp"
#include <cstdint>
#include <cstdlib>
#include <detect/macros.hpp>
#include <string>
#include <sys/syslimits.h>

#if PLATFORM_LINUX

#include <linux/limits.h>
#include <unistd.h>

std::string paths::filepath() {
    char buffer[PATH_MAX];
    readlink("/proc/self/exe", buffer, PATH_MAX);
    return buffer;
}

#elif PLATFORM_SOLARIS

std::string paths::filepath() {
    return "";
}

#elif PLATFORM_WINDOWS

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

#elif PLATFORM_BSD

std::string paths::filepath() {
    return "";
}

#elif PLATFORM_MACOS || PLATFORM_IOS || PLATFORM_WATCHOS || PLATFORM_TVOS

#include <mach-o/dyld.h>

// cppclean-disable-next-line
#include <stdexcept>

#ifndef PATH_MAX
#include <cstddef>
const size_t PATH_MAX = 1024;
#endif

std::string paths::filepath() {
    auto bufsize = static_cast<unsigned int>(PATH_MAX);

    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays,hicpp-avoid-c-arrays,modernize-avoid-c-arrays)
    char buffer[bufsize];

    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay,hicpp-no-array-decay)
    if (_NSGetExecutablePath(buffer, &bufsize) == -1) {
        throw std::length_error("Filepath exceeds maximum path length: " + std::to_string(PATH_MAX));
    }

    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay,hicpp-no-array-decay)
    return realpath(buffer, nullptr);
}

#elif PLATFORM_ANDROID

std::string paths::filepath() {
    char buffer[PATH_MAX];
    readlink("/proc/self/maps", buffer, PATH_MAX);
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
