#include "../../../src/realtime.hpp"
#include "../../services/environment.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Runtime, Dirpath) {
    EXPECT_EQ(paths::dirpath(), test::environment("DIRPATH"));
}
