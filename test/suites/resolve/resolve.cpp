#include "resolve.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/resolve.hpp"
#include <gtest/gtest.h>

TEST(Resolve, Resolve) {
    for (const auto &test : cases) {
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::resolve(test.paths), expected);
    }
}
