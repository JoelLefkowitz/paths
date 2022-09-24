// ʕ •ᴥ•ʔ Paths - paths.hpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_PATHS_H
#define PATHS_PATHS_H

#include <string>
#include <vector>

namespace paths {
    // normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);
} // namespace paths

#endif
