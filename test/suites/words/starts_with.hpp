#ifndef TEST_PATHS_STARTS_WITH_H
#define TEST_PATHS_STARTS_WITH_H

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
