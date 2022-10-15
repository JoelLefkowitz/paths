#ifndef TEST_PATHS_POSIX_PATH_H
#define TEST_PATHS_POSIX_PATH_H

#include <string>
#include <vector>

struct PosixPathTestCase {
    std::string path;
    std::string expected;
};

const std::vector<PosixPathTestCase> cases = {
    {"",            ""       },
    {".",           "."      },
    {"a\\b\\c",     "a/b/c"  },
    {"C:\\a\\b\\c", "/a/b/c" },
    {"\\\\a\\b\\c", "//a/b/c"},
};

#endif
