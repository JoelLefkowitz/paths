#ifndef PATHS_SUITES_CHUNKS_SPLIT_HPP
#define PATHS_SUITES_CHUNKS_SPLIT_HPP

#include <string>
#include <vector>

struct SplitTestCase {
    std::string str;
    std::string delimiter;
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
