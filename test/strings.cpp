#include "../src/strings.hpp"
#include "../src/detect.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace paths;

TEST(Strings, join) {
    EXPECT_EQ(join({""}, "/"), "");
    EXPECT_EQ(join({"", ""}, "/"), "/");
    EXPECT_EQ(join({"", "", ""}, "/"), "//");
    EXPECT_EQ(join({"", "", "", ""}, "/"), "///");

    EXPECT_EQ(join({"", "a"}, "/"), "/a");
    EXPECT_EQ(join({"a", ""}, "/"), "a/");
    EXPECT_EQ(join({"", "a", ""}, "/"), "/a/");

    EXPECT_EQ(join({""}, ""), "");
    EXPECT_EQ(join({"a"}, ""), "a");
    EXPECT_EQ(join({"a, b"}, "-"), "a, b");

    EXPECT_EQ(join({"a", "b", "c"}, "/"), "a/b/c");
    EXPECT_EQ(join({"a", "b", "c"}, "/"), "/a/b/c");
    EXPECT_EQ(join({"a", "b", "c"}, "/"), "a/b/c/");
    EXPECT_EQ(join({"a", "b", "c"}, "/"), "/a/b/c/");
}

TEST(Strings, split) {
    EXPECT_EQ(split("", "/"), std::vector<std::string>({""}));
    EXPECT_EQ(split("/", "/"), std::vector<std::string>({"", ""}));
    EXPECT_EQ(split("//", "/"), std::vector<std::string>({"", "", ""}));
    EXPECT_EQ(split("///", "/"), std::vector<std::string>({"", "", "", ""}));

    EXPECT_EQ(split("/a", "/"), std::vector<std::string>({"", "a"}));
    EXPECT_EQ(split("a/", "/"), std::vector<std::string>({"a", ""}));
    EXPECT_EQ(split("/a/", "/"), std::vector<std::string>({"", "a", ""}));

    EXPECT_EQ(split("", ""), std::vector<std::string>({""}));
    EXPECT_EQ(split("a", ""), std::vector<std::string>({"a"}));
    EXPECT_EQ(split("a, b", "-"), std::vector<std::string>({"a, b"}));

    EXPECT_EQ(split("a/b/c", "/"), std::vector<std::string>({"a", "b", "c"}));
    EXPECT_EQ(split("/a/b/c", "/"), std::vector<std::string>({"a", "b", "c"}));
    EXPECT_EQ(split("a/b/c/", "/"), std::vector<std::string>({"a", "b", "c"}));
    EXPECT_EQ(split("/a/b/c/", "/"), std::vector<std::string>({"a", "b", "c"}));
}

TEST(Strings, head) {
    EXPECT_EQ(head(""), "");
    EXPECT_EQ(head("a"), "a");

    if (platform::sep == '/') {
        EXPECT_EQ(head("a/b"), "b");
        EXPECT_EQ(head("a/b/c"), "c");
        EXPECT_EQ(head("./a/b/c"), "c");
        EXPECT_EQ(head("/a/b/c"), "c");
    }

    if (platform::sep == '\\') {
        EXPECT_EQ(head("a\\b"), "b");
        EXPECT_EQ(head("a\\b\\c"), "c");
        EXPECT_EQ(head(".\\a\\b\\c"), "c");
        EXPECT_EQ(head("C:\\a\\b\\c"), "c");
    }
}

TEST(Strings, tail) {
    EXPECT_EQ(tail(""), "");
    EXPECT_EQ(tail("a"), "");

    if (platform::sep == '/') {
        EXPECT_EQ(tail("a/b"), "a");
        EXPECT_EQ(tail("a/b/c"), "a/b");
        EXPECT_EQ(tail("./a/b/c"), "./a/b");
        EXPECT_EQ(tail("/a/b/c"), "/a/b");
    }

    if (platform::sep == '\\') {
        EXPECT_EQ(tail("a\\b"), "a");
        EXPECT_EQ(tail("a\\b\\c"), "a\\b");
        EXPECT_EQ(tail(".\\a\\b\\c"), ".\\a\\b");
        EXPECT_EQ(tail("C:\\a\\b\\c"), "C:\\a\\b");
    }
}

TEST(Strings, resolve) {
    EXPECT_EQ(resolve({}), "");
    EXPECT_EQ(resolve({"a"}), "a");

    if (platform::sep == '/') {
        EXPECT_EQ(resolve({"a", "b"}), "a/b");
        EXPECT_EQ(resolve({"a", "b", "c"}), "a/b/c");
    }

    if (platform::sep == '\\') {
        EXPECT_EQ(resolve({"a", "b"}), "a\\b");
        EXPECT_EQ(resolve({"a", "b", "c"}), "a\\b\\c");
    }
}

TEST(Strings, segments) {
    EXPECT_EQ(segments(""), std::vector<std::string>());
    EXPECT_EQ(segments("a"), std::vector<std::string>({"a"}));

    if (platform::sep == '/') {
        EXPECT_EQ(segments("a/b"), std::vector<std::string>({"a", "b"}));
        EXPECT_EQ(segments("a/b/c"), std::vector<std::string>({"a", "b", "c"}));
    }

    if (platform::sep == '\\') {
        EXPECT_EQ(segments("a\\b"), std::vector<std::string>({"a", "b"}));
        EXPECT_EQ(segments("a\\b\\c"), std::vector<std::string>({"a", "b", "c"}));
    }
}
