#include "../../src/runtime.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <string>

TEST(runtime, dirname) {
    if (const char *expected = std::getenv("DIRNAME")) {
        EXPECT_EQ(paths::dirname(), expected);
    } else {
        throw std::runtime_error("Missing DIRNAME environment variable");
    }
}
