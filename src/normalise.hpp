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
    //
    // Python equivalent:
    //   os.path.normpath(path)
    //
    // Usage:
    //   normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // Checks if a path is normalised
    //
    // Usage:
    //   normalised("a/b/c") -> true
    //   normalised("a/../a/b/c") -> false
    bool normalised(const std::string &path);

    // Gets the absolute path of a file
    //
    // Python equivalent:
    //   os.path.abspath(path)
    std::string abspath(const std::string &path);

    // Checks if a path is absolute
    //
    // Python equivalent:
    //   os.path.isabs(path)
    //
    // Usage:
    //   absolute("/a") -> true
    //   absolute("a") -> false
    bool absolute(const std::string &path);

    // Finds the relative path from a source to a target
    //
    // Python equivalent:
    //   os.path.relpath(target, source)
    //
    // Usage:
    //   relpath("a/b", "a/c") -> "../c"
    std::string relpath(const std::string &source, const std::string &target);

    // Checks if a path is relative
    //
    // Python equivalent:
    //   not os.path.isabs(path)
    //
    // Usage:
    //   relative("a") -> true
    //   relative("/a") -> false
    bool relative(const std::string &path);
} // namespace paths

#endif
