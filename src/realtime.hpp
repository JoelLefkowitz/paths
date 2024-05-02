#ifndef PATHS_REALTIME_HPP
#define PATHS_REALTIME_HPP

#include <string>

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
}

#endif
