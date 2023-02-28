#include "join.hpp"
#include "../../../src/chunks.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(chunks, join) {
for (const auto &test : cases) {
        EXPECT_EQ(paths::join(test.strs, test.delimiter), test.expected);
    }
}
