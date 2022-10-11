#include "../../src/runtime.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <string>

TEST(runtime, dirpath) {
    GTEST_SKIP();

    if (const char *expected = std::getenv("DIRPATH")) {
        EXPECT_EQ(paths::dirpath(), expected);
    } else {
        throw std::runtime_error("Missing DIRPATH environment variable");
    }
}
