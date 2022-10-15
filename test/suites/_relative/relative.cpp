#include "relative.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/relative.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(relative, relative) {
    for (const auto &test : cases) {
        auto path = paths::platform_path(test.path);
        EXPECT_EQ(paths::relative(path), test.expected);
    }
}
