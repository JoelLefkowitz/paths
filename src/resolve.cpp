// ʕ •ᴥ•ʔ Paths - resolve.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "resolve.hpp"
#include "chunks.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include <string>

std::string paths::resolve(const std::vector<std::string> &paths) {
    return join(normalise(paths), platform::sep);
}

std::vector<std::string> paths::segments(const std::string &path) {
    auto chunks = split(normpath(path), platform::sep);

    std::vector<std::string> filtered;

    auto size = chunks.size();

    for (std::size_t i = 0; i != size; ++i) {
        if (chunks[i] != "" ||
            (0 < i && i < size && chunks[i - 1] != "" && chunks[i + 1] != "")) {
            filtered.push_back(chunks[i]);
        }
    }

    return filtered;
}
