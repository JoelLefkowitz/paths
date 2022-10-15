#include "relative.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/detect.hpp"
#include "../../../src/relative.hpp"
#include "../../support/vectors.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(relative, relative) {
    const auto cases = test::concat(
        common_cases,
        platform::os == platform::Windows ? windows_cases : posix_cases
    );

    for (const auto &test : cases) {
        auto path = paths::platform_path(test.path);
        EXPECT_EQ(paths::relative(path), test.expected);
    }
}
