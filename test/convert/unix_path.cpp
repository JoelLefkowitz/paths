#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(convert, unix_path) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {
        {"",            ""         },
        {".",           "."        },
        {"..",          ".."       },
        {"a",           "a"        },
        {"\\",          "/"        },
        {"\\a",         "/"        },
        {"a\\b",        "a/b"      },
        {"a\\b\\c",     "a/b/c"    },
        {"a\\b\\c.ext", "a/b/c/ext"},
        {"C:\\a\\b\\c", "/a/b"     },
    };

    for (const auto test : cases) {
        EXPECT_EQ(paths::unix_path(test.path), test.expected);
    }
}
