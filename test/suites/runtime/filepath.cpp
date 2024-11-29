#include "../../../src/realtime.hpp"
#include "../../services/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Runtime, Filepath) { EXPECT_EQ(paths::filepath(), test::environment("FILEPATH")); }
