#include "extension.hpp"
#include "../../../src/components.hpp"
#include "../../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(components, extension) {
    // FIXME: 2
    GTEST_SKIP();

    for (const auto &test : cases) {
        auto path     = paths::platform_path(test.path);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::extension(path), expected);
    }
}
