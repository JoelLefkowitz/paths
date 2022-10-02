// ʕ •ᴥ•ʔ Paths - components.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "components.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include "strings.hpp"
#include <string>

std::string paths::head(const std::string &path) {
    auto components = split(normpath(path), platform::sep);
    return components.size() == size_t(1) ? path : components.back();
}

std::string paths::tail(const std::string &path) {
    auto components = split(normpath(path), platform::sep);

    if (!components.empty()) {
        components.pop_back();
    }

    return join(components, platform::sep);
}

std::string paths::drive(const std::string &path) {
    return "";
}
