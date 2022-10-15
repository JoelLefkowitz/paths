// ʕ •ᴥ•ʔ Paths - resolve.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path
// retrieval. https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef LIB_PATHS_RESOLVE_H
#define LIB_PATHS_RESOLVE_H

#include <string>

namespace paths {
    // Joins and normalises path chunks
    //
    // Complies with its python equivalent:
    //   os.path.normpath(os.path.join(*paths))
    //
    // Usage:
    //   resolve({"a", "b", "c"}) -> "a/b/c"
    //   resolve({"a", "b", "..", "c"}) -> "a/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Splits a path into normalised segments
    //
    // Complies with its python equivalent:
    //   os.path.normpath(path).split(os.sep)
    //
    // Usage:
    //   segments("a/b/c") -> {"a", "b", "c"}
    //   segments("a/b/../c") -> {"a", "c"}
    std::vector<std::string> segments(const std::string &path);
} // namespace paths

#endif
