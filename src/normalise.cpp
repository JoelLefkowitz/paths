// ʕ •ᴥ•ʔ Paths - normalise.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "normalise.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "components.hpp"
#include "detect.hpp"
#include "relative.hpp"
#include "vectors.hpp"
#include "words.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> paths::normalise(const std::vector<std::string> &paths) {
    std::vector<std::string> filtered;

    auto contentful = filter(paths, {"", "."});

    for (auto i = contentful.begin(); i != contentful.end(); ++i) {
        if (*i == ".." && !filtered.empty() && filtered.back() != "..") {
            filtered.pop_back();
        } else {
            filtered.push_back(*i);
        }
    }

    return filtered.empty() ? std::vector<std::string>({"."}) : filtered;
}

std::string paths::normpath(const std::string &path) {
    auto normalised = normalise(split(path, platform::sep));

    if (absolute(path)) {
        std::vector<std::string> equivalent = {};

        for (auto i = normalised.begin(); i != normalised.end(); ++i) {
            if (*i != ".." || !equivalent.empty()) {
                equivalent.push_back(*i);
            }
        }

        normalised = equivalent;

        if (normalised == std::vector<std::string>({"."})) {
            normalised = {};
        }
    }

    auto joined = join(normalised, platform::sep);

    if (platform::os == platform::Windows && windows_letter_drive(path) != "") {
        return windows_letter_drive(path) + "/" + joined;
    }

    if (starts_with(path, "//") && !starts_with(path, "///")) {
        return "//" + joined;
    }

    if (starts_with(path, "/")) {
        return "/" + joined;
    }

    return joined;
}
