#include "drive.hpp"
#include "../../../src/components.hpp"
#include "../../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Components, Drive) {
    for (const auto &test : platform_cases) {
        EXPECT_EQ(paths::drive(test.path), test.expected);
    }
}
