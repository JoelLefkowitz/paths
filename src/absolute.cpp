// ʕ •ᴥ•ʔ Paths - absolute.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "absolute.hpp"
#include "detect.hpp"
#include "resolve.hpp"
#include "runtime.hpp"
#include "words.hpp"
#include <string>
#include <vector>

std::string paths::abspath(const std::string &path) {
    return absolute(path) ? path : resolve({dirpath(), path});
}

bool paths::absolute(const std::string &path) {
    return starts_with(path, platform::sep);
}
