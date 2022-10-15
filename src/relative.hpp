// ʕ •ᴥ•ʔ Paths - relative.hpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef LIB_PATHS_RELATIVE_H
#define LIB_PATHS_RELATIVE_H

#include <string>

namespace paths {
    // Finds the relative path from a source to a target
    //
    // Complies with its python equivalent:
    //   os.path.relpath(target, source)
    //
    // Usage:
    //   relpath("a/b", "a/c") -> "../c"
    std::string relpath(const std::string &source, const std::string &target);

    // Checks if a path is relative
    //
    // Complies with its python equivalent:
    //   not os.path.isabs(path)
    //
    // Usage:
    //   relative("a") -> true
    //   relative("/a") -> false
    bool relative(const std::string &path);
} // namespace paths

#endif
