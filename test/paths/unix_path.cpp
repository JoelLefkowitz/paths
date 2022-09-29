#include "../../src/paths.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Paths_Paths, unix_path) {
    struct TestCase {
        std::string path;
        std::string expected;
    };

    // TODO: Add unix_path test cases
    std::vector<TestCase> cases = {};

    for (auto test : cases) {
        EXPECT_EQ(paths::unix_path(test.path), test.expected);
    }
}
