#include "posix_path.hpp"
#include "../../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(convert, posix_path) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::posix_path(test.path), test.expected);
    }
}
