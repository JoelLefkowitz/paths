#ifndef TEST_PATHS_CONTAINS_H
#define TEST_PATHS_CONTAINS_H

#include <vector>

struct ContainsTestCase {
    std::vector<int> vector;
    int              element;
    bool             expected;
};

const std::vector<ContainsTestCase> cases = {
    {{1, 2, 3}, 1, true },
    {{1, 2, 3}, 4, false},
};

#endif
