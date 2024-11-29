#include "count_trailing.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(Vectors, CountTrailing) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::count_trailing(test.vector, test.suffix), test.expected);
    }
}
