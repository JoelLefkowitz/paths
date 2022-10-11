#include "../../src/convert.hpp"
#include "../../src/relative.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(relative, relpath) {
    GTEST_SKIP();

    struct TestCase {
        std::string source;
        std::string target;
        std::string expected;
    };

    std::vector<TestCase> cases = {
        {"a",         "a",     "."            },
        {"a",         "b",     "../a"         },
        {"",          "a",     ".."           },
        {".",         "a",     ".."           },
        {"..",        "a",     "../.."        },
        {"/",         "/a",    ".."           },
        {"/",         "/a/b",  "../.."        },
        {"/..",       "/",     "."            },
        {"C:/a",      "C:/b",  "../a"         },
        {"a/b/c",     "a/d/e", "../../b/c"    },
        {"a/b/c.ext", "a/d/e", "../../b/c.ext"},
    };

    for (auto test : cases) {
        test.source   = paths::platform_path(test.source);
        test.target   = paths::platform_path(test.target);
        test.expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::relpath(test.source, test.target), test.expected);
    }
};
