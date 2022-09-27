#include "../src/runtime.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

TEST(Paths_Runtime, filename) {
    if (const char *expected = std::getenv("FILENAME")) {
        EXPECT_EQ(paths::filename(), expected);
    } else {
        throw std::runtime_error("Missing FILENAME environment variable");
    }
}
