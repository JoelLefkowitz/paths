#include "count_trailing.hpp"
#include "../../../src/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(vectors, count_trailing) {
    for (const auto &test : cases) {
        EXPECT_EQ(
            paths::count_trailing(test.vector, test.suffix),
            test.expected
        );
    }
}
