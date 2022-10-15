#ifndef TEST_PATHS_ENDS_WITH_H
#define TEST_PATHS_ENDS_WITH_H

#include <string>
#include <vector>

struct EndsWithTestCase {
    std::string str;
    std::string prefix;
    bool        expected;
};

const std::vector<EndsWithTestCase> cases = {
    {"",   "",  true },
    {"a",  "",  true },
    {"",   "a", false},
    {"ab", "a", false},
    {"ab", "b", true },
};

#endif
