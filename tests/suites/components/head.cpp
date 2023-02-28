#include "head.hpp"
#include "../../../src/components.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(components, head) {
    for (const auto &test : common_cases) {
        auto path     = paths::platform_path(test.path);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::head(path), expected);
    }

    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::head(test.path), test.expected);
    }
}
