// ʕ •ᴥ•ʔ Paths - normalise.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "normalise.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "detect.hpp"
#include "relative.hpp"
#include "words.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> paths::normalise(const std::vector<std::string> &paths
) {
    std::vector<std::string> contentful;

    std::copy_if(
        paths.begin(),
        paths.end(),
        std::back_inserter(contentful),
        [](const std::string &x) { return x != "" && x != "."; }
    );

    std::vector<std::string> filtered;

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
        std::vector<std::string> _normalised = {};

        for (auto i = normalised.begin(); i != normalised.end(); ++i) {
            if (*i != ".." || !_normalised.empty()) {
                _normalised.push_back(*i);
            }
        }

        normalised = _normalised;

        if (normalised == std::vector<std::string>({"."})) {
            normalised = {};
        }
    }

    auto joined = join(normalised, platform::sep);

    // TODO: Move to drive

    if (starts_with(path, std::string(2, platform::sep)) &&
        !starts_with(path, std::string(3, platform::sep))) {
        return std::string(2, platform::sep) + joined;
    }

    if (absolute(path)) {
        return platform::sep + joined;
    }

    return joined;
}
