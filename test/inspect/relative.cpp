#include "../../src/convert.hpp"
#include "../../src/inspect.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(inspect, relative) {
    GTEST_SKIP();

    std::vector<std::string> true_cases = {};

    std::vector<std::string> false_cases = {};

    for (auto test : true_cases) {
        test = paths::platform_path(test);
        EXPECT_TRUE(paths::relative(test));
    }

    for (auto test : false_cases) {
        test = paths::platform_path(test);
        EXPECT_FALSE(paths::relative(test));
    }
}
