#include "starts_with.hpp"
#include "../../../src/words.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Words, StartsWith) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::starts_with(test.str, test.prefix), test.expected);
    }
}
