// ʕ •ᴥ•ʔ Paths - strings.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "strings.hpp"
#include "detect.hpp"
#include <cstddef>
#include <numeric>
#include <string>
#include <vector>

bool paths::starts_with(const std::string &str, char prefix) {
    return starts_with(str, std::string(1, prefix));
}

bool paths::starts_with(const std::string &str, const std::string &prefix) {
    return str.substr(0, prefix.length()) == prefix;
}

bool paths::ends_with(const std::string &str, char suffix) {
    return ends_with(str, std::string(1, suffix));
}

bool paths::ends_with(const std::string &str, const std::string &suffix) {
    return str.length() >= suffix.length() &&
        str.substr(str.length() - suffix.length(), str.length()) == suffix;
}

std::string paths::join(const std::vector<std::string> &strs, char delimiter) {
    return join(strs, std::string(1, delimiter));
}

std::string paths::join(
    const std::vector<std::string> &strs,
    const std::string              &delimiter
) {
    auto concat = [&delimiter](const std::string &acc, const std::string &x) {
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
    if (str.empty() || delimiter.empty()) {
        return {str};
    }

    std::string copy = str;

    std::vector<std::string> segments;

    size_t pos = 0;

    while ((pos = copy.find(delimiter, pos)) != std::string::npos) {
        segments.push_back(copy.substr(0, pos));
        copy.replace(0, pos + delimiter.length(), "");
    }

    if (!copy.empty() || ends_with(str, delimiter)) {
        segments.push_back(copy);
    }

    return segments;
}
