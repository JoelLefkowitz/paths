#include "windows_path.hpp"
#include "../../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(convert, windows_path) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::windows_path(test.path), test.expected);
    }
}
