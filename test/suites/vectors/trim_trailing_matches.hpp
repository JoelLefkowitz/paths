#ifndef PATHS_SUITES_VECTORS_TRIM_TRAILING_MATCHES_HPP
#define PATHS_SUITES_VECTORS_TRIM_TRAILING_MATCHES_HPP

#include <vector>

struct TrimTrailingMatchesTestCase {
    std::vector<int> x;
    std::vector<int> y;
    std::pair<std::vector<int>, std::vector<int>> expected;
};

const std::vector<TrimTrailingMatchesTestCase> cases = {
    {{},        {},        {{}, {}}        },
    {{1},       {1},       {{}, {}}        },
    {{1},       {2},       {{1}, {2}}      },
    {{1, 2, 3}, {2, 3},    {{1}, {}}       },
    {{1, 2, 3}, {2, 1, 3}, {{1, 2}, {2, 1}}},
};

#endif
