// ʕ •ᴥ•ʔ Paths - resolve.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
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
    auto normalised = normalise(split(path, platform::sep));
    return normalised.empty() ? std::vector<std::string>({""}) : normalised;
}
