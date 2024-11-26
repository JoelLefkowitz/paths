#include "concat.hpp"
#include "../../../src/vectors.tpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, concat) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::concat(test.vector, test.suffix), test.expected);
    }
}
