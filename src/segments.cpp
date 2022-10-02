// ʕ •ᴥ•ʔ Paths - segments.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "segments.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include "strings.hpp"
#include <string>
#include <vector>

std::string paths::resolve(const std::vector<std::string> &paths) {
    return normpath(join(paths, platform::sep));
}

std::vector<std::string> paths::segments(const std::string &path) {
    return split(
        path == "" || path == "." ? "" : normpath(path), platform::sep
    );
}
