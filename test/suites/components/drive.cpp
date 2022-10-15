#include "drive.hpp"
#include "../../../src/components.hpp"
#include "../../../src/convert.hpp"
#include "../../../src/detect.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(components, drive) {
    const auto cases = platform::os == platform::Windows ? windows_cases
                                                         : posix_cases;

    for (const auto &test : cases) {
        auto path     = paths::platform_path(test.path);
        auto expected = paths::platform_path(test.expected);
        EXPECT_EQ(paths::drive(path), expected);
    }
}
