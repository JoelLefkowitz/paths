// ʕ •ᴥ•ʔ Paths - components.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_COMPONENTS_H
#define PATHS_COMPONENTS_H

#include <string>

namespace paths {
    // Gets a path's head
    // Python equivalent: os.path.split(os.path.normpath(path))[1]
    // Usage: head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // Gets a path's tail
    // Python equivalent: os.path.split(os.path.normpath(path))[0]
    // Usage: tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Gets a path's drive
    // Python equivalent: os.path.splitdrive(path)[0]
    // Usage: drive("C:\a\b\c") -> "C:"
    std::string drive(const std::string &path);
} // namespace paths

#endif
