#ifndef PATHS_CONVERT_HPP
#define PATHS_CONVERT_HPP

#include <string>

namespace paths {
    constexpr char posix_sep   = '/';
    constexpr char windows_sep = '\\';

    // Converts a Windows path to a Posix path
    //
    // Usage:
    //   posix_path("") -> ""
    //   posix_path(".") -> "."
    //   posix_path("a\b\c") -> "a/b/c"
    //   posix_path("C:\a\b\c") -> "/a/b/c"
    //   posix_path("\\a\b\c") -> "//a/b/c"
    std::string posix_path(std::string path);

    // Converts a Posix path to a Windows path
    //
    // Usage:
    //   windows_path("") -> ""
    //   windows_path(".") -> "."
    //   windows_path("a/b/c") -> "a\b\c"
    //   windows_path("C:/a/b/c") -> "C:\a\b\c"
    //   windows_path("//a/b/c") -> "\\a\b\c"
    std::string windows_path(std::string path);

    // Converts a path to a Windows path in a Windows
    // environment and Posix path in a Posix environment
    //
    // Usage:
    // platform_path("") -> ""
    // platform_path(".") -> "."
    //
    // [Windows]
    //   platform_path("a/b") -> "a\b"
    //   platform_path("a\b") -> "a\b"
    //
    // [Otherwise]
    //   platform_path("a/b") -> "a/b"
    //   platform_path("a\b") -> "a/b"
    std::string platform_path(const std::string &path);
}

#endif
