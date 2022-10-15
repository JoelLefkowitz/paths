#ifndef TEST_PATHS_RESOLVE_H
#define TEST_PATHS_RESOLVE_H

#include <string>
#include <vector>

struct ResolveTestCase {
    std::vector<std::string> paths;
    std::string              expected;
};

const std::vector<ResolveTestCase> cases = {};

#endif
