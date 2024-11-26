#include "filter.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, filter) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::filter(test.vector, test.targets), test.expected);
    }
}
