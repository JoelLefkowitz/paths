#ifndef TEST_PATHS_RELPATH_H
#define TEST_PATHS_RELPATH_H

#include <string>
#include <vector>

struct RelpathTestCase {
    std::string source;
    std::string target;
    std::string expected;
};

const std::vector<RelpathTestCase> cases = {};

#endif
