#include "segments.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/resolve.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>

TEST(resolve, segments) {
    for (const auto &test : common_cases) {
        EXPECT_EQ(paths::segments(paths::platform_path(test.path)), test.expected);
    }

    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::segments(test.path), test.expected);
    }
}
