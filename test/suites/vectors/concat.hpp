#ifndef PATHS_SUITES_VECTORS_CONCAT_HPP
#define PATHS_SUITES_VECTORS_CONCAT_HPP

#include <string>
#include <vector>

struct ConcatTestCase {
    std::vector<int> vector;
    std::vector<int> suffix;
    std::vector<int> expected;
};

const std::vector<ConcatTestCase> cases = {
    {{},  {},  {}    },
    {{1}, {},  {1}   },
    {{},  {2}, {2}   },
    {{1}, {2}, {1, 2}},
};

#endif
