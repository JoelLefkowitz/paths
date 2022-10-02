// ʕ •ᴥ•ʔ Paths - strings.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_STRINGS_H
#define PATHS_STRINGS_H

#include <string>
#include <vector>

namespace paths {
    // Determines if a path starts with a prefix
    bool starts_with(const std::string &str, char prefix);

    // Determines if a path starts with a prefix
    bool starts_with(const std::string &str, const std::string &prefix);

    // Determines if a path ends with a suffix
    bool ends_with(const std::string &str, char suffix);

    // Determines if a path ends with a suffix
    bool ends_with(const std::string &str, const std::string &suffix);

    // Joins strings with a delimeter
    // Usage: join({"a", "b", "c"}, ',') -> "a,b,c"
    std::string join(const std::vector<std::string> &strs, char delimiter);

    // Joins strings with a delimeter
    // Usage: join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(
        const std::vector<std::string> &strs,
        const std::string              &delimiter = ", "
    );

    // Splits a string at each occurrence of a delimeter
    // Usage: split("a,b,c", ',') -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits a string at each occurrence of a delimeter
    // Usage: split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter = " "
    );
} // namespace paths

#endif
