#include "split.hpp"
#include "../../../src/chunks.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Chunks, Split) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::split(test.str, test.delimiter), test.expected);
    }
}
