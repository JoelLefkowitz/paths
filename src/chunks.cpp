// ʕ •ᴥ•ʔ Paths - chunks.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "chunks.hpp"
#include "words.hpp"
#include <cstddef>
#include <numeric>
#include <string>
#include <vector>

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

    auto joined =
        std::accumulate(strs.begin(), strs.end(), std::string(), concat);

    return joined.substr(0, joined.length() - delimiter.length());
}

std::vector<std::string> paths::split(const std::string &str, char delimiter) {
    return split(str, std::string(1, delimiter));
}

std::vector<std::string> paths::split(
    const std::string &str,
    const std::string &delimiter
) {
    if (str.empty()) {
        return {str};
    }

    if (delimiter.empty()) {
        std::vector<std::string> strs;

        for (auto i = str.begin(); i != str.end(); ++i) {
            strs.push_back(std::string(1, *i));
        }

        return strs;
    }

    size_t pos = 0;

    std::string copy = str;

    std::vector<std::string> chunks;

    while ((pos = copy.find(delimiter, 0)) != std::string::npos) {
        chunks.push_back(copy.substr(0, pos));
        copy.replace(0, pos + delimiter.length(), "");
    }

    if (!copy.empty() || ends_with(str, delimiter)) {
        chunks.push_back(copy);
    }

    return chunks;
}
