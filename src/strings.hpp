// ʕ •ᴥ•ʔ Paths - strings.cpp ʕ•ᴥ• ʔ
// OS specific path manipulation including retrieving the executable's path.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#ifndef PATHS_STRINGS_H
#define PATHS_STRINGS_H

#include <string>
#include <vector>

namespace paths {
    std::string join(const std::vector<std::string> &strs, char delimiter);
    std::string join(const std::vector<std::string> &strs, const std::string &delimiter = ", ");

    std::vector<std::string> split(const std::string &str, char delimiter);
    std::vector<std::string> split(const std::string &str, const std::string &delimiter = " ");

    std::string head(const std::string &path);
    std::string tail(const std::string &path);

    std::string resolve(const std::vector<std::string> &paths);

    std::vector<std::string> segments(const std::string &path);
} // namespace paths

#endif
