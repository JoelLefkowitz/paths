#include "ends_with.hpp"
#include "../../../src/words.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(words, ends_with) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::ends_with(test.str, test.prefix), test.expected);
    }
}
