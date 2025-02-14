#ifndef PATHS_SUITES_VECTORS_COUNT_LEADING_HPP
#define PATHS_SUITES_VECTORS_COUNT_LEADING_HPP

#include <cstddef>
#include <vector>

struct CountLeadingTestCase {
    std::vector<int> vector;
    int prefix;
    size_t expected;
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
