#include "count_leading.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, count_leading) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::count_leading(test.vector, test.prefix), test.expected);
    }
}
