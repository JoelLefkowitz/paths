#include "reverse.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, reverse) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::reverse(test.vector), test.expected);
    }
}
