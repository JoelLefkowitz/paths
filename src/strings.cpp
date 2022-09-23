// ʕ •ᴥ•ʔ Paths - strings.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "strings.hpp"
#include "detect.hpp"
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

std::string paths::join(const std::vector<std::string> &strs, char delimiter) {
    return join(strs, std::string(1, delimiter));
}

std::string paths::join(
    const std::vector<std::string> &strs,
    const std::string              &delimiter
) {
    std::function<std::string(const std::string &, const std::string &)> concat =
        [&delimiter](const auto &acc, const auto &x) {
            return acc + x + delimiter;
        };

    auto joined = std::accumulate(strs.begin(), strs.end(), std::string(), concat);

    return joined.substr(0, joined.length() - delimiter.length());
}

std::vector<std::string> paths::split(const std::string &str, char delimiter) {
    return split(str, std::string(1, delimiter));
}

std::vector<std::string> paths::split(
    const std::string &str,
    const std::string &delimiter
) {
    std::string str_copy = str;

    size_t pos = 0;

    std::vector<std::string> segments;

    while ((pos = str_copy.find(delimiter)) != std::string::npos && pos > 0) {
        segments.push_back(str_copy.substr(0, pos));
        str_copy.erase(0, pos + delimiter.length());
    }

    segments.push_back(str_copy);
    return segments;
}

std::string paths::head(const std::string &path) {
    return split(path, platform::sep).back();
}

std::string paths::tail(const std::string &path) {
    auto segments = split(path, platform::sep);
    segments.pop_back();
    return join(segments, platform::sep);
}

std::string paths::resolve(const std::vector<std::string> &paths) {
    return join(paths, platform::sep);
}

std::vector<std::string> paths::segments(const std::string &path) {
    return path.empty() ? std::vector<std::string>() : split(path, platform::sep);
}
