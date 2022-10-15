#include "../../../src/runtime.hpp"
#include "../../utils/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(runtime, dirname) {
    EXPECT_EQ(paths::dirname(), test::environment("DIRNAME"));
}
