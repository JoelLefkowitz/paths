#ifndef PATHS_SUITES_WORDS_STARTS_WITH_HPP
#define PATHS_SUITES_WORDS_STARTS_WITH_HPP

#include <string>
#include <vector>

struct StartsWithTestCase {
    std::string str;
    std::string prefix;
    bool        expected;
};

const std::vector<StartsWithTestCase> cases = {
    {"",   "",  true },
    {"a",  "",  true },
    {"",   "a", false},
    {"ab", "a", true },
    {"ab", "b", false},
};

#endif
