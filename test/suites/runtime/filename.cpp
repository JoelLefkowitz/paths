#include "../../../src/runtime.hpp"
#include "../../utils/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(runtime, filename) {
    EXPECT_EQ(paths::filename(), test::environment("FILENAME"));
}
