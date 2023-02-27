#ifndef TEST_PATHS_DRIVE_H
#define TEST_PATHS_DRIVE_H

#include <string>
#include <vector>

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
    {"C:/a/b/c", "C:"   },
    {"//a/b/c",  "//a/b"},
};

const std::vector<DriveTestCase> posix_cases = {
    {"",         ""},
    {".",        ""},
    {"..",       ""},
    {"a/b/c",    ""},
    {"/a/b/c",   ""},
    {"C:/a/b/c", ""},
    {"//a/b/c",  ""},
};

#endif
