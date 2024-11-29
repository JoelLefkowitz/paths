#include "contains.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(Vectors, Contains) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::contains(test.vector, test.element), test.expected);
    }
}
