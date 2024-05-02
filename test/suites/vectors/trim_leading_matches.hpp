#ifndef PATHS_SUITES_VECTORS_TRIM_LEADING_MATCHES_HPP
#define PATHS_SUITES_VECTORS_TRIM_LEADING_MATCHES_HPP

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
