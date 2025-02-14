#ifndef PATHS_SUITES_VECTORS_CONTAINS_HPP
#define PATHS_SUITES_VECTORS_CONTAINS_HPP

#include <vector>

struct ContainsTestCase {
    std::vector<int> vector;
    int element;
    bool expected;
};

const std::vector<ContainsTestCase> cases = {
    {{1, 2, 3}, 1, true },
    {{1, 2, 3}, 4, false},
};

#endif
