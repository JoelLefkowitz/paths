// ʕ •ᴥ•ʔ Paths - components.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "components.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "convert.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include "resolve.hpp"
#include "words.hpp"
#include <cstddef>
#include <iostream>
#include <string>

std::string paths::drive(const std::string &path) {
    if (platform::os != platform::Windows) {
        return "";
    }

    auto sep   = path.find(windows_sep, 0);
    auto colon = path.find(":", 0);

    if (sep != std::string::npos && colon != std::string::npos &&
        sep == colon + 1) {
        return path.substr(0, sep);
    }

    if (starts_with(path, std::string(2, windows_sep)) &&
        (sep = path.find(windows_sep, 2)) != std::string::npos) {
        return path.substr(0, path.find(windows_sep, sep + 1));
    }

    return "";
}

std::string paths::head(const std::string &path) {
    return segments(path).back();
}

std::string paths::tail(const std::string &path) {
    auto normalised = segments(path);
    normalised.pop_back();
    return join(normalised, platform::sep);
}

std::string paths::extension(const std::string &path) {
    auto pos = path.find_last_of(".", std::string::npos);
    return pos != std::string::npos && path[pos] != '.' ? path.substr(pos) : "";
}
