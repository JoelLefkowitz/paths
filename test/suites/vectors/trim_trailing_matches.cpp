#include "trim_trailing_matches.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(Vectors, TrimTrailingMatches) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::trim_trailing_matches(test.x, test.y), test.expected);
    }
}
