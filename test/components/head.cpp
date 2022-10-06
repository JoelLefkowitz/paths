#include "../../src/components.hpp"
#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(components, head) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {
        {".",         "."    },
        {"..",        ".."   },
        {"a",         "a"    },
        {"/",         ""     },
        {"/.",        "."    },
        {"/..",       ".."   },
        {"/a",        "a"    },
        {"./",        ""     },
        {"./.",       "."    },
        {"./..",      ".."   },
        {"./a",       "a"    },
        {"../",       ""     },
        {"../.",      "."    },
        {"../..",     ".."   },
        {"../a",      "a"    },
        {"a/",        ""     },
        {"a/.",       "."    },
        {"a/..",      ".."   },
        {"a/b",       "b"    },
        {"//",        ""     },
        {"//.",       "."    },
        {"//..",      ".."   },
        {"//a",       "a"    },
        {"/./",       ""     },
        {"/./.",      "."    },
        {"/./..",     ".."   },
        {"/./a",      "a"    },
        {"/../",      ""     },
        {"/../.",     "."    },
        {"/../..",    ".."   },
        {"/../a",     "a"    },
        {"/a/",       ""     },
        {"/a/.",      "."    },
        {"/a/..",     ".."   },
        {"/a/b",      "b"    },
        {".//",       ""     },
        {".//.",      "."    },
        {".//..",     ".."   },
        {".//a",      "a"    },
        {"././",      ""     },
        {"././.",     "."    },
        {"././..",    ".."   },
        {"././a",     "a"    },
        {"./../",     ""     },
        {"./../.",    "."    },
        {"./../..",   ".."   },
        {"./../a",    "a"    },
        {"./a/",      ""     },
        {"./a/.",     "."    },
        {"./a/..",    ".."   },
        {"./a/b",     "b"    },
        {"..//",      ""     },
        {"..//.",     "."    },
        {"..//..",    ".."   },
        {"..//a",     "a"    },
        {".././",     ""     },
        {".././.",    "."    },
        {".././..",   ".."   },
        {".././a",    "a"    },
        {"../../",    ""     },
        {"../../.",   "."    },
        {"../../..",  ".."   },
        {"../../a",   "a"    },
        {"../a/",     ""     },
        {"../a/.",    "."    },
        {"../a/..",   ".."   },
        {"../a/b",    "b"    },
        {"a//",       ""     },
        {"a//.",      "."    },
        {"a//..",     ".."   },
        {"a//b",      "b"    },
        {"a/./",      ""     },
        {"a/./.",     "."    },
        {"a/./..",    ".."   },
        {"a/./b",     "b"    },
        {"a/../",     ""     },
        {"a/../.",    "."    },
        {"a/../..",   ".."   },
        {"a/../b",    "b"    },
        {"a/b/",      ""     },
        {"a/b/.",     "."    },
        {"a/b/..",    ".."   },
        {"a/b/c",     "c"    },
        {"C:/a/b/c",  "c"    },
        {"a/b/c.ext", "c.ext"},
    };

    for (auto test : cases) {
        test.path = paths::platform_path(test.path);
        EXPECT_EQ(paths::head(test.path), test.expected);
    }
}
