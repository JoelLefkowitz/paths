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

    std::vector<TestCase> cases = {};

    for (const auto test : cases) {
        EXPECT_EQ(paths::unix_path(test.path), test.expected);
    }
}
