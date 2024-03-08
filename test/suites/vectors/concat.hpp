#ifndef TEST_PATHS_CONCAT_H
#define TEST_PATHS_CONCAT_H

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
