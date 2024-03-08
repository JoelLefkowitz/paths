#include "trim_leading_matches.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, trim_leading_matches) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::trim_leading_matches(test.x, test.y), test.expected);
    }
}
