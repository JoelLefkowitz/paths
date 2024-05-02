#include "../../../src/absolute.hpp"
#include "../../support/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(absolute, abspath) { EXPECT_EQ(paths::abspath("a/b/c"), test::environment("ABSPATH")); }
