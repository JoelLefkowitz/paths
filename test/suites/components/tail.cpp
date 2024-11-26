#include "tail.hpp"
#include "../../../src/components.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(components, tail) {
    for (const auto &test : common_cases) {
        auto path     = paths::platform_path(test.path);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::tail(path), expected);
    }

    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::tail(test.path), test.expected);
    }
}
