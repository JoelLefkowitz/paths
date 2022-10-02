#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(convert, platform_path) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {};

    for (auto test : cases) {
        EXPECT_EQ(paths::platform_path(test.path), test.expected);
    }
}
