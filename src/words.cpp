// ʕ •ᴥ•ʔ Paths - words.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "words.hpp"
#include <string>

bool paths::starts_with(const std::string &str, char prefix) {
    return starts_with(str, std::string(1, prefix));
}

bool paths::starts_with(const std::string &str, const std::string &prefix) {
    return str.substr(0, prefix.length()) == prefix;
}

bool paths::ends_with(const std::string &str, char suffix) {
    return ends_with(str, std::string(1, suffix));
}

bool paths::ends_with(const std::string &str, const std::string &suffix) {
    return str.length() >= suffix.length() &&
        str.substr(str.length() - suffix.length(), str.length()) == suffix;
}
