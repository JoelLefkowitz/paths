#include "normalise.hpp"
#include "../../../src/normalise.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(normalise, normalise) {
    for (const auto &test : cases) {
        EXPECT_EQ(paths::normalise(test.paths), test.expected);
    }
}
