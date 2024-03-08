#ifndef TEST_PATHS_COUNT_LEADING_H
#define TEST_PATHS_COUNT_LEADING_H

#include <cstddef>
#include <vector>

struct CountLeadingTestCase {
    std::vector<int> vector;
    int              prefix;
    size_t           expected;
};

const std::vector<CountLeadingTestCase> cases = {
    {{},        1, 0},
    {{1},       1, 1},
    {{1, 1},    1, 2},
    {{1, 2, 1}, 1, 1},
    {{1, 1, 2}, 1, 2},
    {{1, 1, 1}, 1, 3},
};

#endif
