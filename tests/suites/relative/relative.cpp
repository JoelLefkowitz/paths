#include "relative.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/relative.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(relative, relative) {
    for (const auto &test : common_cases) {
        EXPECT_EQ(
            paths::relative(paths::platform_path(test.path)),
            test.expected
        );
    }

    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::relative(test.path), test.expected);
    }
}
