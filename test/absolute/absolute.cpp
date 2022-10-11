#include "../../src/absolute.hpp"
#include "../../src/convert.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(absolute, absolute) {
    std::vector<std::string> true_cases = {
        "/",
        "/.",
        "/..",
        "/a",
    };

    std::vector<std::string> false_cases = {
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

    for (auto test : true_cases) {
        test = paths::platform_path(test);
        EXPECT_TRUE(paths::absolute(test));
    }

    for (auto test : false_cases) {
        test = paths::platform_path(test);
        EXPECT_FALSE(paths::absolute(test));
    }
}
