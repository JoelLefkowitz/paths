// ʕ •ᴥ•ʔ Paths - components.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef LIB_PATHS_COMPONENTS_H
#define LIB_PATHS_COMPONENTS_H

#include <string>

namespace paths {
    // Gets a path's drive
    //
    // Complies with its python equivalent:
    //   os.path.splitdrive(path)[0]
    //
    // Usage [Windows]:
    //   drive("C:/a/b") -> "C:"
    //   drive("//a/b/c") -> "//a/b"
    //
    // Usage [Otherwise]:
    //   drive("C:/a/b") -> ""
    //   drive("//a/b/c") -> ""
    std::string drive(const std::string &path);

    // Gets a path's head
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[1]
    //
    // Usage:
    //   head("a") -> "a"
    //   head("a/b") -> "b"
    //   head("a/b.ext") -> "b.ext"
    std::string head(const std::string &path);

    // Gets a path's tail
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[0]
    //
    // Usage:
    //   tail("a/b") -> "a"
    //   tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Gets a path's root
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.splitext(path)[0])[0]
    //
    // Usage:
    //   root("a/b.ext") -> "b"
    std::string root(const std::string &path);

    // Gets a path's extension
    //
    // Complies with its python equivalent:
    //   os.path.splitext(path)[1]
    //
    // Usage:
    //   extension("a/b.ext") -> ".ext"
    //   extension("a/b.ext1.ext2") -> ".ext1.ext2"
    //   extension("a/b") -> ""
    std::string extension(const std::string &path);
} // namespace paths

#endif
