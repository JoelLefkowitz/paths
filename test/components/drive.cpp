#include "../../src/components.hpp"
#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(components, drive) {
    GTEST_SKIP();

    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {};

    for (auto test : cases) {
        test.path     = paths::platform_path(test.path);
        test.expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::drive(test.path), test.expected);
    }
}
