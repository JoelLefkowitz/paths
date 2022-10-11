#include "../../src/normalise.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(normalise, normalise) {
    struct TestCase {
        std::vector<std::string> paths;
        std::vector<std::string> expected;
    };

    std::vector<TestCase> cases = {};

    for (auto test : cases) {
        EXPECT_EQ(paths::normalise(test.paths), test.expected);
    }
};
