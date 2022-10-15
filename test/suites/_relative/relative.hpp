#ifndef TEST_PATHS_RELATIVE_H
#define TEST_PATHS_RELATIVE_H

#include <string>
#include <vector>

struct RelativeTestCase {
    std::string path;
    bool        expected;
};

const std::vector<RelativeTestCase> cases = {};

#endif
