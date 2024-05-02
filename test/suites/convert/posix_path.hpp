#ifndef PATHS_SUITES_CONVERT_POSIX_PATH_HPP
#define PATHS_SUITES_CONVERT_POSIX_PATH_HPP

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
