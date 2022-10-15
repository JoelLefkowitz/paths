#include "segments.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/resolve.hpp"
#include <gtest/gtest.h>

TEST(resolve, segments) {
    for (const auto &test : cases) {
        auto path = paths::platform_path(test.path);
        EXPECT_EQ(paths::segments(path), test.expected);
    }
}
