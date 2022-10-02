#include "../../src/convert.hpp"
#include "../../src/normalise.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(normalise, relpath) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {};

    for (auto test : cases) {
        test.path     = paths::platform_path(test.path);
        test.expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::normpath(test.path), test.expected);
    }
};
