// ʕ •ᴥ•ʔ Paths - normalise.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_NORMALISE_H
#define PATHS_NORMALISE_H

#include <string>

namespace paths {
    // Normalises a path
    // Usage: normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // Finds the relative path from a source to a target
    // Usage: relpath("a/b", "a/c") -> "../c"
    std::string relpath(const std::string &source, const std::string &target);
} // namespace paths

#endif
