// ʕ •ᴥ•ʔ Paths - runtime.hpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_RUNTIME_H
#define PATHS_RUNTIME_H

#include <string>

namespace paths {
    // Gets the path of the current executable file
    std::string filename();

    // Gets the dirname of the current executable file
    std::string dirname();

    // Gets the absolute path of a file
    std::string abspath(const std::string &path);
} // namespace paths

#endif
