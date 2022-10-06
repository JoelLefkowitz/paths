#include "../../src/components.hpp"
#include "../../src/convert.hpp"
#include "../../src/detect.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(components, drive) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases;

    if (platform::os == platform::Windows) {
        cases = {
            {".",           ""        },
            {"..",          ""        },
            {"\\",          ""        },
            {"\\a",         ""        },
            {"\\\\a\\b\\c", "\\\\a\\b"},
            {"C:\\a\\b",    "C:"      },
        };
    } else {
        cases = {
            {".",       ""},
            {"..",      ""},
            {"/",       ""},
            {"/a",      ""},
            {"//a/b/c", ""},
            {"C:/a/b",  ""},
        };
    }

    for (auto test : cases) {
        EXPECT_EQ(paths::drive(test.path), test.expected);
    }
}
