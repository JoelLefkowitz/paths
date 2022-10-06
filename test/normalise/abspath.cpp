#include "../../src/convert.hpp"
#include "../../src/normalise.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <string>

TEST(runtime, abspath) {
    auto absolute = paths::platform_path("/a/b/c");
    EXPECT_EQ(paths::abspath(absolute), absolute);

    if (const char *expected = std::getenv("ABSPATH")) {
        EXPECT_EQ(paths::abspath(paths::platform_path("a/b/c")), expected);
    } else {
        throw std::runtime_error("Missing ABSPATH environment variable");
    }
}
