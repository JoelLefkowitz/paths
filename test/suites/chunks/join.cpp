#include "join.hpp"
#include "../../../src/chunks.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Chunks, Join) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::join(test.strs, test.delimiter), test.expected);
    }
}
