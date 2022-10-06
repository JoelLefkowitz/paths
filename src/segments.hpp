// ʕ •ᴥ•ʔ Paths - segments.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_SEGMENTS_H
#define PATHS_SEGMENTS_H

#include <string>
#include <vector>

namespace paths {
    // Joins and normalises path segments
    //
    // Python equivalent:
    //   os.path.normpath(os.path.join(*paths))
    //
    // Usage:
    //   resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Normalises and splits a path into segments
    //
    // Python equivalent:
    //   os.path.normpath(path).split(os.path.sep)
    //
    // Usage:
    //   segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);
} // namespace paths

#endif
