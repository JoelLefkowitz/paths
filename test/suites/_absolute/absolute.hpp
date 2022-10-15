#ifndef TEST_PATHS_ABSOLUTE_H
#define TEST_PATHS_ABSOLUTE_H

#include <string>
#include <vector>

struct AbsoluteTestCase {
    std::string path;
    bool        expected;
};

const std::vector<AbsoluteTestCase> cases = {};

#endif
