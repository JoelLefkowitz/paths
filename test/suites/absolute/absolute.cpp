#include "absolute.hpp"
#include "../../../src/absolute.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/detect.hpp"
#include "../../utils/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(absolute, absolute) {
    const auto cases = test::concat(
        common_cases,
        platform::os == platform::Windows ? windows_cases : posix_cases
    );

    for (const auto &test : cases) {
        auto path = paths::platform_path(test.path);
        EXPECT_EQ(paths::absolute(path), test.expected);
    }
}
