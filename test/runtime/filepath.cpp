#include "../../src/runtime.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <string>

TEST(runtime, filepath) {
    if (const char *expected = std::getenv("FILEPATH")) {
        EXPECT_EQ(paths::filepath(), expected);
    } else {
        throw std::runtime_error("Missing FILEPATH environment variable");
    }
}
