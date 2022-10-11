// ʕ •ᴥ•ʔ Paths - components.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "components.hpp"
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
    auto normalised = segments(path);
    return normalised.size() == size_t(1) ? path : normalised.back();
}

std::string paths::tail(const std::string &path) {
    auto normalised = segments(path);

    if (!normalised.empty()) {
        normalised.pop_back();
    }

    return join(normalised, platform::sep);
}

std::string paths::root(const std::string &path) {
    return "";
}

std::string paths::extension(const std::string &path) {
    return "";
}
