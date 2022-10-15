// ʕ •ᴥ•ʔ Paths - components.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path
// retrieval. https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "components.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include "resolve.hpp"
#include <cstddef>
#include <string>

std::string paths::drive(const std::string &path) {
    return "";
}

std::string paths::head(const std::string &path) {
    return segments(path).back();
}

std::string paths::tail(const std::string &path) {
    auto normalised = segments(path);
    normalised.pop_back();
    return drive(path) + join(normalised, platform::sep);
}

std::string paths::root(const std::string &path) {
    return "";
}

std::string paths::extension(const std::string &path) {
    return "";
}
