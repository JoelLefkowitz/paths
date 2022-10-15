#ifndef TEST_PATHS_SPLIT_H
#define TEST_PATHS_SPLIT_H

#include <string>
#include <vector>

struct SplitTestCase {
    std::string              str;
    std::string              delimiter;
    std::vector<std::string> expected;
};

const std::vector<SplitTestCase> cases = {
    {"",      "",   {""}           },
    {"",      "-",  {""}           },
    {"a",     "",   {"a"}          },
    {"a",     "-",  {"a"}          },
    {"ab",    "",   {"a", "b"}     },
    {"a-b",   "-",  {"a", "b"}     },
    {"a--b",  "-",  {"a", "", "b"} },
    {"a--b",  "--", {"a", "b"}     },
    {"abc",   "",   {"a", "b", "c"}},
    {"a-b-c", "-",  {"a", "b", "c"}},
};

#endif
