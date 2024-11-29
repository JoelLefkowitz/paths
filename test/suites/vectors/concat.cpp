#include "concat.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(Vectors, Concat) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::concat(test.vector, test.suffix), test.expected);
    }
}
