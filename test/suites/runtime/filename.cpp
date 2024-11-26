#include "../../../src/realtime.hpp"
#include "../../services/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(runtime, filename) { EXPECT_EQ(paths::filename(), test::environment("FILENAME")); }
