// ʕ •ᴥ•ʔ Paths - relative.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "relative.hpp"
#include "absolute.hpp"
#include <string>

std::string paths::relpath(const std::string &source, const std::string &target) {
    return "";
}

bool paths::relative(const std::string &path) {
    return !absolute(path);
}
