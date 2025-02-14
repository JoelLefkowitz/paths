#ifndef PATHS_SUITES_WORDS_ENDS_WITH_HPP
#define PATHS_SUITES_WORDS_ENDS_WITH_HPP

#include <string>
#include <vector>

struct EndsWithTestCase {
    std::string str;
    std::string prefix;
    bool expected;
};

const std::vector<EndsWithTestCase> cases = {
    {"",   "",  true },
    {"a",  "",  true },
    {"",   "a", false},
    {"ab", "a", false},
    {"ab", "b", true },
};

#endif
