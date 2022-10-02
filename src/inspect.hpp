// ʕ •ᴥ•ʔ Paths - inspect.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_INSPECT_H
#define PATHS_INSPECT_H

#include <string>

namespace paths {
    // Checks if a path is absolute
    bool absolute(const std::string &path);

    // Checks if a path is normalised
    bool normalised(const std::string &path);

    // Checks if a path is relative
    bool relative(const std::string &path);
} // namespace paths

#endif
