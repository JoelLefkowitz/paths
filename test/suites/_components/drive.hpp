#ifndef TEST_PATHS_DRIVE_H
#define TEST_PATHS_DRIVE_H

#include <string>
#include <vector>

struct DriveTestCase {
    std::string path;
    std::string expected;
};

const std::vector<DriveTestCase> cases = {
    // {"",         ""                    },
    // {".",        ""                    },
    // {"..",       ""                    },
    // {"a/b/c",    ""                    },
    // {"/a/b/c",   ""                    },
    // {"//a/b/c",  windows ? "//a/b" : ""},
    // {"C:/a/b/c", windows ? "C:" : ""   },
};

#endif
