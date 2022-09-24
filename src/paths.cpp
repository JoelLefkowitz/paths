// ʕ •ᴥ•ʔ Paths - paths.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "strings.hpp"
#include "paths.hpp"
#include "detect.hpp"
#include <string>
#include <vector>

std::string paths::head(const std::string &path) {
    auto segments = split(path, platform::sep);
    return segments.empty() ? "" : segments.back();
}

std::string paths::tail(const std::string &path) {
    auto segments = split(path, platform::sep);

    if (!segments.empty()) {
        segments.pop_back();
    }

    return join(segments, platform::sep);
}

std::string paths::normpath(const std::string &path) {
    return path;
}

std::string paths::resolve(const std::vector<std::string> &paths) {
    return normpath(join(paths, platform::sep));
}

std::vector<std::string> paths::segments(const std::string &path) {
    return split(normpath(path), platform::sep);
}
