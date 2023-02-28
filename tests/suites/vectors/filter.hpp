#ifndef TEST_PATHS_FILTER_H
#define TEST_PATHS_FILTER_H

#include <vector>

struct FilterTestCase {
    std::vector<int> vector;
    std::vector<int> targets;
    std::vector<int> expected;
};

const std::vector<FilterTestCase> cases = {
    {{1, 2, 3},    {1},    {2, 3}},
    {{1, 2, 1, 3}, {1},    {2, 3}},
    {{1, 1, 2, 3}, {1, 2}, {3}   },
};

#endif
