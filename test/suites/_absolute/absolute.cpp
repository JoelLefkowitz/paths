#include "absolute.hpp"
#include "../../../src/absolute.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/detect.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(absolute, absolute) {
    for (const auto &test : cases) {
        auto path = paths::platform_path(test.path);
        EXPECT_EQ(paths::absolute(path), test.expected);
    }
}
