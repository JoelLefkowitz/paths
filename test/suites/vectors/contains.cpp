#include "contains.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, contains) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::contains(test.vector, test.element), test.expected);
    }
}
