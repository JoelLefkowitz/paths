#ifndef PATHS_SUITES_VECTORS_REVERSE_HPP
#define PATHS_SUITES_VECTORS_REVERSE_HPP

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
