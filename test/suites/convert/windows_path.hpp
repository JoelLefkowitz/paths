#ifndef PATHS_SUITES_CONVERT_WINDOWS_PATH_HPP
#define PATHS_SUITES_CONVERT_WINDOWS_PATH_HPP

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
