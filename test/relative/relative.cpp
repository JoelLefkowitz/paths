#include "../../src/relative.hpp"
#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(relative, relative) {
    std::vector<std::string> true_cases = {
        "",
        ".",
        "..",
        "a",
        "./",
        "./.",
        "./..",
        "./a",
        "../",
        "../.",
        "../..",
        "../a",
        "a/",
        "a/.",
        "a/..",
        "a/b",
    };

    std::vector<std::string> false_cases = {
        "/",
        "/.",
        "/..",
        "/a",
    };

    for (auto test : true_cases) {
        test = paths::platform_path(test);
        EXPECT_TRUE(paths::relative(test));
    }

    for (auto test : false_cases) {
        test = paths::platform_path(test);
        EXPECT_FALSE(paths::relative(test));
    }
}
