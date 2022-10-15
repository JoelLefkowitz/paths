#ifndef TEST_PATHS_POSIX_PATH_H
#define TEST_PATHS_POSIX_PATH_H

#include <string>
#include <vector>

struct PosixPathTestCase {
    std::string path;
    std::string expected;
};

const std::vector<PosixPathTestCase> cases = {};

// TODO: Test that the path is not normalised

#endif
