// ʕ •ᴥ•ʔ Paths - normalise.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef LIB_PATHS_NORMALISE_H
#define LIB_PATHS_NORMALISE_H

#include <string>

namespace paths {
    // Normalises path chunks
    //
    // Usage:
    //   normalise({"a", ".", "b"}) -> {"a", "b"}
    //   normalise({"a", "..", "b"}) -> {"b"}
    std::vector<std::string> normalise(const std::vector<std::string> &paths);

    // Normalises a path
    //
    // Complies with its python equivalent:
    //   os.path.normpath(path)
    //
    // Usage:
    //   normpath("a/../b/c") -> "a/c"
    std::string normpath(const std::string &path);
} // namespace paths

#endif
