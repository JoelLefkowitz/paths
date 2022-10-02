// ʕ •ᴥ•ʔ Paths - inspect.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "inspect.hpp"
#include "detect.hpp"
#include "strings.hpp"
#include <string>

bool paths::absolute(const std::string &path) {
    return starts_with(path, platform::sep);
}

// TODO: Write without calling normpath()
bool paths::normalised(const std::string &path) {
    return false;
}

bool paths::relative(const std::string &path) {
    return !absolute(path);
}
