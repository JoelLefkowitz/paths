#include "relpath.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/relative.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Relative, Relpath) {
    for (const auto &test : cases) {
        auto source   = paths::platform_path(test.source);
        auto target   = paths::platform_path(test.target);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::relpath(source, target), expected);
    }
}
