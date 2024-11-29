#include "trim_leading_matches.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(Vectors, TrimLeadingMatches) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::trim_leading_matches(test.x, test.y), test.expected);
    }
}
