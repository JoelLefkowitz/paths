#include "normpath.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/normalise.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(normalise, normpath) {
    for (const auto &test : common_cases) {
        auto path     = paths::platform_path(test.path);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::normpath(path), expected);
    }

    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::normpath(test.path), test.expected);
    }
}
