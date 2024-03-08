#ifndef TEST_PATHS_TRIM_LEADING_MATCHES_H
#define TEST_PATHS_TRIM_LEADING_MATCHES_H

#include <vector>

struct TrimLeadingMatchesTestCase {
    std::vector<int>                              x;
    std::vector<int>                              y;
    std::pair<std::vector<int>, std::vector<int>> expected;
};

const std::vector<TrimLeadingMatchesTestCase> cases = {
    {{},        {},        {{}, {}}        },
    {{1},       {1},       {{}, {}}        },
    {{1},       {2},       {{1}, {2}}      },
    {{1, 2, 3}, {1, 2},    {{3}, {}}       },
    {{1, 2, 3}, {1, 3, 2}, {{2, 3}, {3, 2}}},
};

#endif
