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
    constexpr char unix_sep    = '/';
    constexpr char windows_sep = '\\';

    // Normalises the path
    // Python equivalent: os.path.normpath(path)
    // Usage: normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // Gets the path's head
    // Python equivalent: os.path.split(os.path.normpath(path))[1]
    // Usage: head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // Gets the path's tail
    // Python equivalent: os.path.split(os.path.normpath(path))[0]
    // Usage: tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Joins and normalises the path segments
    // Python equivalent: os.path.normpath(os.path.join(*paths))
    // Usage: resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Normalises and splits the path into segments
    // Python equivalent: os.path.normpath(path).split(os.path.sep)
    // Usage: segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);

    // TODO: Add python equivalents
    // TODO: Update README.md
    // Converts a Unix path to a Windows path
    // Python equivalent: 
    // Usage: unix_path("a\\b\\c") -> "a/b/c"
    std::string unix_path(const std::string &path);

    // Converts a Windows path to a Unix path
    // Python equivalent: 
    // Usage: windows_path("a/b/c") -> "a\\b\\c"
    std::string windows_path(const std::string &path);
} // namespace paths

#endif
