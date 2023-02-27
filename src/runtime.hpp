// ʕ •ᴥ•ʔ Paths - runtime.hpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef LIB_PATHS_RUNTIME_H
#define LIB_PATHS_RUNTIME_H

#include <string>

const int PATH_MAX = 4096;

namespace paths {
    // Gets the path of the current executable file
    std::string filepath();

    // Gets the name of the current executable file
    std::string filename();

    // Gets the path of the directory of the current
    // executable file
    std::string dirpath();

    // Gets the name of the directory of the current
    // executable file
    std::string dirname();
} // namespace paths

#endif
