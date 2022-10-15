// ʕ •ᴥ•ʔ Paths - words.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "words.hpp"
#include <string>

bool paths::starts_with(const std::string &str, char prefix) {
    return !str.empty() && str.front() == prefix;
}

bool paths::starts_with(const std::string &str, const std::string &prefix) {
    return str.length() >= prefix.length() &&
        str.substr(0, prefix.length()) == prefix;
}

bool paths::ends_with(const std::string &str, char suffix) {
    return !str.empty() && str.back() == suffix;
}

bool paths::ends_with(const std::string &str, const std::string &suffix) {
    return str.length() >= suffix.length() &&
        str.substr(str.length() - suffix.length(), str.length()) == suffix;
}
