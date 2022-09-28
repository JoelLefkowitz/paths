#include "../../src/paths.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Paths_Paths, windows_path) {
    struct TestCase {
        std::string path;
        std::string expected;
    };

    // TODO: Add windows_path test cases
    std::vector<TestCase> cases = {};

    for (auto test : cases) {
        EXPECT_EQ(paths::windows_path(test.path), test.expected);
    }
}
