#include "../../src/convert.hpp"
#include "../../src/runtime.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(runtime, absolute) {
    GTEST_SKIP();

    std::vector<std::string> true_cases = {};

    std::vector<std::string> false_cases = {};

    for (auto test : true_cases) {
        test = paths::platform_path(test);
        EXPECT_TRUE(paths::absolute(test));
    }

    for (auto test : false_cases) {
        test = paths::platform_path(test);
        EXPECT_FALSE(paths::absolute(test));
    }
}
