// ʕ •ᴥ•ʔ Paths - chunks.hpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef LIB_PATHS_CHUNKS_H
#define LIB_PATHS_CHUNKS_H

#include <string>
#include <vector>

namespace paths {
    // Joins strings with a delimeter
    //
    // Usage:
    //   join({"a", "b", "c"}, ',') -> "a,b,c"
    std::string join(const std::vector<std::string> &strs, char delimiter);

    // Joins strings with a delimeter
    //
    // Usage:
    //   join({"a", "b", "c"}, ",") -> "a,b,c"
    std::string join(
        const std::vector<std::string> &strs,
        const std::string              &delimiter
    );

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("abc", '') -> {"a", "b", "c"}
    //   split("a,b,c", ',') -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("abc", "") -> {"a", "b", "c"}
    //   split("a,b,c", ",") -> {"a", "b", "c"}
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter
    );
} // namespace paths

#endif
