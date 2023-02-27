#include "normpath.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/detect.hpp"
#include "../../../src/normalise.hpp"
#include "../../support/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(normalise, normpath) {
    const auto cases = test::concat(
        common_cases,
        platform::os == platform::Windows ? windows_cases : posix_cases
    );

    for (const auto &test : cases) {
        auto path     = paths::platform_path(test.path);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::normpath(path), expected);
    }
}
