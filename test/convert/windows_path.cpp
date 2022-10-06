#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(convert, windows_path) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {
        {"",          ""           },
        {".",         "."          },
        {"..",        ".."         },
        {"a",         "a"          },
        {"/",         "\\"         },
        {"/a",        "\\"         },
        {"a/b",       "a\\b"       },
        {"a/b/c",     "a\\b\\c"    },
        {"a/b/c.ext", "a\\b\\c/ext"},
        {"C:/a/b/c",  "C:\\a\\b"   },
    };

    for (auto test : cases) {
        EXPECT_EQ(paths::windows_path(test.path), test.expected);
    }
}
