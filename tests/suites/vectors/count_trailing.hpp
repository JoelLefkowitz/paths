#ifndef TEST_PATHS_COUNT_TRAILING_H
#define TEST_PATHS_COUNT_TRAILING_H

#include <cstddef>
#include <vector>

struct CountTrailingTestCase {
    std::vector<int> vector;
    int              suffix;
    size_t           expected;
};

const std::vector<CountTrailingTestCase> cases = {
    {{},        1, 0},
    {{1},       1, 1},
    {{1, 1},    1, 2},
    {{1, 2, 1}, 1, 1},
    {{2, 1, 1}, 1, 2},
    {{1, 1, 1}, 1, 3},
};

#endif
