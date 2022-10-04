// ʕ •ᴥ•ʔ Paths - normalise.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "normalise.hpp"
#include "detect.hpp"
#include "runtime.hpp"
#include "strings.hpp"
#include <algorithm>
#include <string>
#include <vector>

std::string paths::normpath(const std::string &path) {
    auto components = split(path, platform::sep);

    std::vector<std::string> contentful;

    std::copy_if(
        components.begin(),
        components.end(),
        std::back_inserter(contentful),
        [](const std::string &x) { return x != "" && x != "."; }
    );

    if (contentful.empty() && !starts_with(path, platform::sep)) {
        return ".";
    }

    std::vector<std::string> filtered;

    for (auto i = contentful.begin(); i != contentful.end(); ++i) {
        if (*i == ".." && !filtered.empty() && filtered.back() != "..") {
            filtered.pop_back();
        } else {
            filtered.push_back(*i);
        }
    }

    auto normalised = join(filtered, platform::sep);

    if (absolute(path)) {
        normalised = platform::sep + normalised;
    }

    return normalised;
}

bool paths::normalised(const std::string &path) {
    return false;
}

std::string paths::relpath(
    const std::string &source,
    const std::string &target
) {
    return "";
}

bool paths::relative(const std::string &path) {
    return !absolute(path);
}
