#include "../../../src/runtime.hpp"
#include "../../support/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(runtime, filename) {
EXPECT_EQ(paths::filename(), test::environment("FILENAME"));
}
