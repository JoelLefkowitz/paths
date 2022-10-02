// ʕ •ᴥ•ʔ Paths - convert.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "convert.hpp"
#include <string>

std::string paths::unix_path(const std::string &path) {
    std::string copy(path);
    std::replace(copy.begin(), copy.end(), paths::windows_sep, paths::unix_sep);
    return copy;
}

std::string paths::windows_path(const std::string &path) {
    std::string copy(path);
    std::replace(copy.begin(), copy.end(), paths::unix_sep, paths::windows_sep);
    return copy;
}

std::string paths::platform_path(const std::string &path) {
    return path;
}
