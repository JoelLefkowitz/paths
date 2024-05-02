#ifndef PATHS_SUITES_VECTORS_FILTER_HPP
#define PATHS_SUITES_VECTORS_FILTER_HPP

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
