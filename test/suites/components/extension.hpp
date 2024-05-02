#ifndef PATHS_SUITES_COMPONENTS_EXTENSION_HPP
#define PATHS_SUITES_COMPONENTS_EXTENSION_HPP

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
