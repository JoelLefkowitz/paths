// ʕ •ᴥ•ʔ Paths - components.hpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
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
    // Usage:
    // [Windows]
    //   drive("C:/a/b") -> "C:"
    //   drive("//a/b/c") -> "//a/b"
    //
    // [Otherwise]
    //   drive("C:/a/b") -> ""
    //   drive("//a/b/c") -> ""
    std::string drive(const std::string &path);

    // Gets a path's head
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[1]
    //
    // Usage:
    //   head("") -> "."
    //   head(".") -> "."
    //   head("a") -> "a"
    //   head("a/b") -> "b"
    //
    // [Windows]
    //   head("C:") -> ""
    //   head("//a/b") -> "b"
    //
    // [Otherwise]
    //   head("C:") -> "C:"
    //   head("//a/b") -> "b"
    std::string head(const std::string &path);

    // Gets a path's tail
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[0]
    //
    // Usage:
    //   tail("") -> ""
    //   tail(".") -> ""
    //   tail("a") -> ""
    //   tail("/a") -> "/"
    //   tail("a/b") -> "a"
    //   tail("a/b/c") -> "a/b"
    //
    // [Windows]
    //   tail("C:") -> ""
    //   tail("//a/b") -> "//a/b"
    //   tail("//a/b/c") -> "//a/b"
    //
    // [Otherwise]
    //   tail("C:") -> ""
    //   tail("//a/b") -> "//a"
    //   tail("//a/b/c") -> "//a/b"
    std::string tail(const std::string &path);

    // Gets a path's extension
    //
    // Complies with its python equivalent:
    //   os.path.splitext(path)[1]
    //
    // Usage:
    //   extension("a") -> ""
    //   extension("a/b") -> ""
    //   extension("a/b.x") -> ".x"
    //   extension("a/b.x.y") -> ".y"
    std::string extension(const std::string &path);
} // namespace paths

#endif
