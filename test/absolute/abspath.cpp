#include "../../src/absolute.hpp"
#include "../../src/convert.hpp"
#include <cstdlib>
#include <gtest/gtest.h>
#include <string>

TEST(absolute, abspath) {
    GTEST_SKIP();

    auto absolute = paths::platform_path("/a/b/c");

    EXPECT_EQ(paths::abspath(absolute), absolute);

    if (const char *expected = std::getenv("ABSPATH")) {
        EXPECT_EQ(paths::abspath(paths::platform_path("a/b/c")), expected);
    } else {
        throw std::runtime_error("Missing ABSPATH environment variable");
    }
}
