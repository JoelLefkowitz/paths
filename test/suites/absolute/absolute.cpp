#include "absolute.hpp"
#include "../../../src/absolute.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(Absolute, Absolute) {
    for (const auto &test : common_cases) {
        EXPECT_EQ(paths::absolute(paths::platform_path(test.path)), test.expected);
    }

    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::absolute(test.path), test.expected);
    }
}
