// ʕ •ᴥ•ʔ Paths - convert.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_CONVERT_H
#define PATHS_CONVERT_H

#include <string>

namespace paths {
    constexpr char unix_sep    = '/';
    constexpr char windows_sep = '\\';

    // Converts a Windows path to a Unix path
    //
    // Usage:
    //   unix_path("a\b\c") -> "a/b/c"
    //   unix_path: {"C:\a\b\c", "/a/b/c" },
    std::string unix_path(const std::string &path);

    // Converts a Unix path to a Windows path
    //
    // Usage:
    //   windows_path("a/b/c") -> "a\b\c"
    //   windows_path("C:/a/b/c") -> "C:\a\b\c"
    std::string windows_path(const std::string &path);

    // Converts a path to a Windows path in a Windows
    // environment and Unix path in a Unix environment
    //
    // Usage [Windows]:
    //   platform_path("a/b") -> "a\\b"
    //   platform_path("a\\b") -> "a\\b"
    //
    // Usage [Otherwise]:
    //   platform_path("a/b") -> "a/b"
    //   platform_path("a\\b") -> "a/b"
    std::string platform_path(const std::string &path);
} // namespace paths

#endif
