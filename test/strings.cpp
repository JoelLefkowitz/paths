#include "../src/strings.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Paths, starts_with) {
    struct TestCase {
        std::string str;
        std::string prefix;
    };

    std::vector<TestCase> cases = {
        {"",    ""   },
        {"abc", ""   },
        {"abc", "a"  },
        {"abc", "ab" },
        {"abc", "abc"},
    };

    for (const auto test : cases) {
        EXPECT_TRUE(paths::starts_with(test.str, test.prefix));
    }

    cases = {
        {"",    "x"   },
        {"abc", "x"   },
        {"abc", "xa"  },
        {"abc", "ax"  },
        {"abc", "abcc"},
    };

    for (const auto test : cases) {
        EXPECT_FALSE(paths::starts_with(test.str, test.prefix));
    }
}

TEST(Paths, ends_with) {
    struct TestCase {
        std::string str;
        std::string suffix;
    };

    std::vector<TestCase> cases = {
        {"",    ""   },
        {"abc", ""   },
        {"abc", "c"  },
        {"abc", "bc" },
        {"abc", "abc"},
    };

    for (const auto test : cases) {
        EXPECT_TRUE(paths::ends_with(test.str, test.suffix));
    }

    cases = {
        {"",    "x"   },
        {"abc", "x"   },
        {"abc", "xa"  },
        {"abc", "ax"  },
        {"abc", "aabc"},
    };

    for (const auto test : cases) {
        EXPECT_FALSE(paths::ends_with(test.str, test.suffix));
    }
}

TEST(Paths, join) {
    struct TestCase {
        std::vector<std::string> strs;
        std::string              delimiter;
        std::string              expected;
    };

    std::vector<TestCase> cases = {
        {{""},                       "/", ""          },
        {{"", ""},                   "/", "/"         },
        {{"", "", ""},               "/", "//"        },
        {{"", "", "", ""},           "/", "///"       },

        {{"", "a"},                  "/", "/a"        },
        {{"a", ""},                  "/", "a/"        },
        {{"", "a", ""},              "/", "/a/"       },

        {{""},                       "",  ""          },
        {{"", ""},                   "",  ""          },
        {{"a"},                      "",  "a"         },
        {{"a", "b"},                 "",  "ab"        },

        {{"a", "b", "c"},            "/", "a/b/c"     },
        {{"", "a", "b", "c"},        "/", "/a/b/c"    },
        {{"a", "b", "c", ""},        "/", "a/b/c/"    },
        {{"", "a", "b", "c", ""},    "/", "/a/b/c/"   },

        {{".", "a", "b", "c"},       "/", "./a/b/c"   },
        {{"..", "a", "b", "c"},      "/", "../a/b/c"  },
        {{"a", "..", "a", "b", "c"}, "/", "a/../a/b/c"},
    };

    for (const auto test : cases) {
        EXPECT_EQ(paths::join(test.strs, test.delimiter), test.expected);
    }
}

TEST(Paths, split) {
    struct TestCase {
        std::string              str;
        std::string              delimiter;
        std::vector<std::string> expected;
    };

    std::vector<TestCase> cases = {
        {"",           "/", {""}                      },
        {"/",          "/", {"", ""}                  },
        {"//",         "/", {"", "", ""}              },
        {"///",        "/", {"", "", "", ""}          },

        {"/a",         "/", {"", "a"}                 },
        {"a/",         "/", {"a", ""}                 },
        {"/a/",        "/", {"", "a", ""}             },

        {"",           "",  {""}                      },
        {"a",          "",  {"a"}                     },
        {"ab",         "",  {"ab"}                    },

        {"a/b/c",      "/", {"a", "b", "c"}           },
        {"/a/b/c",     "/", {"", "a", "b", "c"}       },
        {"a/b/c/",     "/", {"a", "b", "c", ""}       },
        {"/a/b/c/",    "/", {"", "a", "b", "c", ""}   },

        {"./a/b/c",    "/", {".", "a", "b", "c"}      },
        {"../a/b/c",   "/", {"..", "a", "b", "c"}     },
        {"a/../a/b/c", "/", {"a", "..", "a", "b", "c"}},
    };

    for (const auto test : cases) {
        EXPECT_EQ(paths::split(test.str, test.delimiter), test.expected);
    }
}
