#include "segments.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/detect.hpp"
#include "../../../src/resolve.hpp"
#include "../../utils/vectors.hpp"
#include <gtest/gtest.h>

TEST(resolve, segments) {
    const auto cases = test::concat(
        common_cases,
        platform::os == platform::Windows ? windows_cases : posix_cases
    );

    for (const auto &test : cases) {
        auto path = paths::platform_path(test.path);
        EXPECT_EQ(paths::segments(path), test.expected);
    }
}
