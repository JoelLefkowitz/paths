#ifndef TEST_PATHS_DRIVE_H
#define TEST_PATHS_DRIVE_H

#include <string>
#include <vector>

// cppclean-disable-next-line
#include "../../../src/detect.hpp"

struct DriveTestCase {
    std::string path;
    std::string expected;
};

const std::vector<DriveTestCase> windows_cases = {
    {"",         ""     },
    {".",        ""     },
    {"..",       ""     },
    {"a/b/c",    ""     },
    {"/a/b/c",   ""     },
    {"//a/b/c",  "//a/b"},
    {"///a/b/c", ""     },
    {"C:/a/b/c", "C:"   },
};

const std::vector<DriveTestCase> posix_cases = {
    {"",         ""},
    {".",        ""},
    {"..",       ""},
    {"a/b/c",    ""},
    {"/a/b/c",   ""},
    {"//a/b/c",  ""},
    {"///a/b/c", ""},
    {"C:/a/b/c", ""},
};

const std::vector<DriveTestCase> platform_cases = platform::os == platform::Windows ? windows_cases : posix_cases;

#endif
