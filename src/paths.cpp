// ʕ •ᴥ•ʔ Paths - paths.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "paths.hpp"
#include "detect.hpp"
#include "strings.hpp"
#include <algorithm>
#include <string>
#include <vector>

std::string paths::normpath(const std::string &path) {
    if (path == "/") {
        return path;
    }

    auto components = split(path, platform::sep);
    auto contentful = [](const std::string &x) { return x != "" && x != "."; };

    if (std::none_of(components.begin(), components.end(), contentful)) {
        return ".";
    }

    std::vector<std::string> content;

    std::copy_if(
        components.begin(), components.end(), std::back_inserter(content), contentful
    );

    std::vector<std::string> normalised;

    for (auto i = content.begin(); i != content.end(); ++i) {
        if (*i == ".." && !normalised.empty() && normalised.back() != "..") {
            normalised.pop_back();
        } else {
            normalised.push_back(*i);
        }
    }

    return join(normalised, platform::sep);
}

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

std::string paths::resolve(const std::vector<std::string> &paths) {
    return normpath(join(paths, platform::sep));
}

std::vector<std::string> paths::segments(const std::string &path) {
    return split(path == "" || path == "." ? "" : normpath(path), platform::sep);
}

std::string paths::unix_path(const std::string &path) {
    std::string copy(path);
    std::replace(copy.begin(), copy.end(), paths::windows_sep, paths::unix_sep);
    return copy;
}

std::string paths::windows_path(const std::string &path) {
    std::string copy(path);
    std::replace(copy.begin(), copy.end(), paths::unix_sep, paths::windows_sep);
    return copy;
}
