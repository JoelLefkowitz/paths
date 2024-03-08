#ifndef TEST_PATHS_REVERSE_H
#define TEST_PATHS_REVERSE_H

#include <vector>

struct ReverseTestCase {
    std::vector<int> vector;
    std::vector<int> expected;
};

const std::vector<ReverseTestCase> cases = {
    {{},        {}       },
    {{1},       {1}      },
    {{1, 2, 3}, {3, 2, 1}},
};

#endif
