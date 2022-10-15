#include "relpath.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/relative.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(relative, relpath) {
    // FIXME: 7
    GTEST_SKIP();

    for (const auto &test : cases) {
        auto source   = paths::platform_path(test.source);
        auto target   = paths::platform_path(test.target);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::relpath(source, target), expected);
    }
}
