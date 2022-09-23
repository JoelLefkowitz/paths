// ʕ •ᴥ•ʔ Paths - strings.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_RUNTIME_H
#define PATHS_RUNTIME_H

#include <string>

namespace paths {
    std::string filename();
    std::string dirname();
} // namespace paths

#endif
