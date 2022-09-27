// ʕ •ᴥ•ʔ Paths - strings.hpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_STRINGS_H
#define PATHS_STRINGS_H

#include <string>
#include <vector>

namespace paths {
    // Determines if the path starts with the prefix
    // Python equivalent: str.startswith(prefix)
    // Usage: starts_with("a/b/c", "a/") -> true
    bool starts_with(const std::string &str, char prefix);

    // Determines if the path starts with the prefix
    // Python equivalent: str.startswith(prefix)
    // Usage: starts_with("a/b/c", "a/") -> true
    bool starts_with(const std::string &str, const std::string &prefix);

    // Determines if the path ends with the suffix
    // Python equivalent: str.endswith(suffix)
    // Usage: ends_with("a/b/c", "/c") -> true
    bool ends_with(const std::string &str, char suffix);

    // Determines if the path ends with the suffix
    // Python equivalent: str.endswith(suffix)
    // Usage: ends_with("a/b/c", "/c") -> true
    bool ends_with(const std::string &str, const std::string &suffix);

    // Joins the strings with the delimeter
    // Python equivalent: delimeter.join(strs)
    // Usage: join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(const std::vector<std::string> &strs, char delimiter);

    // Joins the strings with the delimeter
    // Python equivalent: delimeter.join(strs)
    // Usage: join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(
        const std::vector<std::string> &strs,
        const std::string              &delimiter = ", "
    );

    // Splits the string at the delimeter
    // Python equivalent: str.split(delimeter)
    // Usage: split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits the string at the delimeter
    // Python equivalent: str.split(delimeter)
    // Usage: split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter = " "
    );
} // namespace paths

#endif
