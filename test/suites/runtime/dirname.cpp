#include "../../../src/realtime.hpp"
#include "../../services/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(runtime, dirname) { EXPECT_EQ(paths::dirname(), test::environment("DIRNAME")); }
