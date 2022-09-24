// ʕ •ᴥ•ʔ Paths - paths.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "paths.hpp"
#include "detect.hpp"
#include "strings.hpp"
#include <set>
#include <string>
#include <vector>

std::string paths::normpath(const std::string &path) {
    auto components = split(path, platform::sep);

    std::vector<std::string> target;

    for (auto i = components.begin(); (i + 1) != components.end(); ++i) {
        target.push_back(*i);
    }

    target.push_back(components.back());

    return join(target, platform::sep);
}

std::string paths::head(const std::string &path) {
    auto components = split(normpath(path), platform::sep);
    return components.empty() ? "" : components.back();
}

std::string paths::tail(const std::string &path) {
    auto components = split(normpath(path), platform::sep);

    if (!components.empty()) {
        components.pop_back();
    }

    return join(components, platform::sep);
}

std::string paths::resolve(const std::vector<std::string> &paths) {
    return normpath(join(paths, platform::sep));
}

std::vector<std::string> paths::segments(const std::string &path) {
    return split(normpath(path), platform::sep);
}
