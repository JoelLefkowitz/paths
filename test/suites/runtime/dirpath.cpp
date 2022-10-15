#include "../../../src/runtime.hpp"
#include "../../utils/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(runtime, dirpath) {
    EXPECT_EQ(paths::dirpath(), test::environment("DIRPATH"));
}
