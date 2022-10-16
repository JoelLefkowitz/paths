// ʕ •ᴥ•ʔ Paths - convert.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "convert.hpp"
#include "detect.hpp"
#include <algorithm>
#include <iostream>
#include <string>

std::string paths::posix_path(const std::string &path) {
    auto sep   = path.find(windows_sep, 0);
    auto colon = path.find(":", 0);

    std::string copy = (sep == std::string::npos ||
                        colon == std::string::npos || sep != colon + 1)
        ? path
        : path.substr(sep, path.length() - sep);

    std::replace(
        copy.begin(),
        copy.end(),
        paths::windows_sep,
        paths::posix_sep
    );

    return copy;
}

std::string paths::windows_path(const std::string &path) {
    std::string copy(path);

    std::replace(
        copy.begin(),
        copy.end(),
        paths::posix_sep,
        paths::windows_sep
    );

    return copy;
}

std::string paths::platform_path(const std::string &path) {
    return platform::os == platform::Windows ? windows_path(path)
                                             : posix_path(path);
}
