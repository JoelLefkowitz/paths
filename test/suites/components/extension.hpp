#ifndef TEST_PATHS_EXTENSION_H
#define TEST_PATHS_EXTENSION_H

#include <string>
#include <vector>

struct ExtensionTestCase {
    std::string path;
    std::string expected;
};

const std::vector<ExtensionTestCase> cases = {
    {"",        ""  },
    {".",       ""  },
    {".x",      ""  },
    {"a",       ""  },
    {"a.x",     ".x"},
    {"..",      ""  },
    {"..x",     ""  },
    {"...",     ""  },
    {"...x",    ""  },
    {"a/b",     ""  },
    {"a/b.x",   ".x"},
    {"a/b.x.y", ".y"},
};

#endif
