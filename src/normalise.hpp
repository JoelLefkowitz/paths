#ifndef PATHS_NORMALISE_HPP
#define PATHS_NORMALISE_HPP

#include <string>
#include <vector>

namespace paths {
    // Normalises path chunks
    //
    // Complies with its python equivalent:
    //   os.path.normpath(os.path.join(*paths)).split(os.sep)
    //
    // Usage:
    //   normalise({}) -> {"."}
    //   normalise({""}) -> {"."}
    //   normalise({"a", ".", "b"}) -> {"a", "b"}
    //   normalise({"a", "..", "b"}) -> {"b"}
    std::vector<std::string> normalise(const std::vector<std::string> &paths);

    // Normalises a path
    //
    // Complies with its python equivalent:
    //   os.path.normpath(path)
    //
    // Usage:
    //   normpath("") -> "."
    //   normpath("/..") -> "/"
    //   normpath("a/./b") -> "a/b"
    //   normpath("a/../b/c") -> "a/c"
    //
    // [Windows]
    //   normpath("C:/..") -> "C:"
    //   normpath("//a/b/..") -> "//a/b"
    //
    // [Otherwise]
    //   normpath("C:/..") -> ""
    //   normpath("//a/b") -> "//a/b"
    //   normpath("//a/b/..") -> "//a"
    //   normpath("///a/b") -> "/a/b"
    std::string normpath(const std::string &path);
}

#endif
