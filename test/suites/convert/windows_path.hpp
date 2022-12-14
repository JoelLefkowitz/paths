#ifndef TEST_PATHS_WINDOWS_PATH_H
#define TEST_PATHS_WINDOWS_PATH_H

#include <string>
#include <vector>

struct WindowsPathTestCase {
    std::string path;
    std::string expected;
};

const std::vector<WindowsPathTestCase> cases = {
    {"",         ""           },
    {".",        "."          },
    {"a/b/c",    "a\\b\\c"    },
    {"C:/a/b/c", "C:\\a\\b\\c"},
    {"//a/b/c",  "\\\\a\\b\\c"},
};

#endif
