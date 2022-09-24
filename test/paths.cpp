#include "../src/paths.hpp"
#include "../src/detect.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Paths, normpath) {
    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {
        {"a",               "a"       },
        {"a/b",             "a/b"     },
        {"a/b/c",           "a/b/c"   },

        {"",                "."       },
        {".",               "."       },
        {"./",              "."       },
        {"././",            "."       },
        {"././.",           "."       },

        {"./a/b/c",         "a/b/c"   },
        {"a/b/c/.",         "a/b/c"   },
        {"a/./b/c",         "a/b/c"   },

        {"a//b/c",          "a/b/c"   },
        {"a///b/c",         "a/b/c"   },
        {"a///b/c",         "a/b/c"   },

        {"..",              ".."      },
        {"../..",           "../.."   },
        {"../a/b/c",        "../a/b/c"},
        {"a/../a/b/c",      "a/b/c"   },
        {"a/b/c/..",        "a/b"     },
        {"a/../a/../a/b/c", "a/b/c"   },
        {"a/b/../../a/b/c", "a/b/c"   },
        {"a/../../a/b/c",   "../a/b/c"},
    };

    for (const auto test : cases) {
        EXPECT_EQ(paths::normpath(test.path), test.expected);
    }
}

TEST(Paths, head) {
    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases;

    if (platform::sep == '/') {
        cases = {
            {"",           ""  },
            {".",          "." },
            {"..",         ".."},
            {"../..",      ".."},
            {"a",          "a" },
            {"a/b",        "b" },
            {"a/b/c",      "c" },
            {"./a/b/c",    "c" },
            {"/a/b/c",     "c" },
            {"a/../a/b/c", "c" },
        };
    }

    if (platform::sep == '\\') {
        cases = {
            {"",               ""  },
            {".",              "." },
            {"..",             ".."},
            {"..\\..",         ".."},
            {"a",              "a" },
            {"a\\b",           "b" },
            {"a\\b\\c",        "c" },
            {".\\a\\b\\c",     "c" },
            {"\\a\\b\\c",      "c" },
            {"a\\..\\a\\b\\c", "c" },
        };
    }

    for (const auto test : cases) {
        EXPECT_EQ(paths::head(test.path), test.expected);
    }
}

TEST(Paths, tail) {
    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases;

    if (platform::sep == '/') {
        cases = {
            {"",           ""        },
            {".",          ""        },
            {"..",         ""        },
            {"../..",      ".."      },
            {"a",          ""        },
            {"a/b",        "a"       },
            {"a/b/c",      "a/b"     },
            {"./a/b/c",    "./a/b"   },
            {"/a/b/c",     "/a/b"    },
            {"a/../a/b/c", "a/../a/b"},
        };
    }

    if (platform::sep == '\\') {
        cases = {
            {"",               ""           },
            {".",              ""           },
            {"..",             ""           },
            {"..\\..",         ".."         },
            {"a",              ""           },
            {"a\\b",           "a"          },
            {"a\\b\\c",        "a\\b"       },
            {".\\a\\b\\c",     ".\\a\\b"    },
            {"\\a\\b\\c",      "\\a\\b"     },
            {"a\\..\\a\\b\\c", "a\\..\\a\\b"},
        };

        for (const auto test : cases) {
            EXPECT_EQ(paths::head(test.path), test.expected);
        }
    }
}

TEST(Paths, resolve) {
    struct TestCase {
        std::vector<std::string> paths;
        std::string              expected;
    };

    std::vector<TestCase> cases;

    if (platform::sep == '/') {
        cases = {
            {{},                         "."       },
            {{""},                       "."       },
            {{"a"},                      "a"       },
            {{"a", "b"},                 "a/b"     },
            {{"a", "b", "c"},            "a/b/c"   },
            {{".", "a", "b", "c"},       "a/b/c"   },
            {{"..", "a", "b", "c"},      "../a/b/c"},
            {{"a", "..", "a", "b", "c"}, "a/b/c"   },
        };
    }

    if (platform::sep == '\\') {
        cases = {
            {{},                         "."          },
            {{""},                       "."          },
            {{"a"},                      "a"          },
            {{"a", "b"},                 "a\\b"       },
            {{"a", "b", "c"},            "a\\b\\c"    },
            {{".", "a", "b", "c"},       "a\\b\\c"    },
            {{"..", "a", "b", "c"},      "..\\a\\b\\c"},
            {{"a", "..", "a", "b", "c"}, "a\\b\\c"    },
        };
    }

    for (const auto test : cases) {
        EXPECT_EQ(paths::resolve(test.paths), test.expected);
    }
}

TEST(Paths, segments) {
    struct TestCase {
        std::string              path;
        std::vector<std::string> expected;
    };

    std::vector<TestCase> cases;

    if (platform::sep == '/') {
        cases = {
            {"",           {""}                 },
            {".",          {""}                 },
            {"a",          {"a"}                },
            {"a/b",        {"a", "b"}           },
            {"a/b/c",      {"a", "b", "c"}      },
            {"./a/b/c",    {"a", "b", "c"}      },
            {"../a/b/c",   {"..", "a", "b", "c"}},
            {"a/../a/b/c", {"a", "b", "c"}      },
        };
    }

    if (platform::sep == '\\') {
        cases = {
            {"",               {""}                 },
            {"a",              {"a"}                },
            {"a\\b",           {"a", "b"}           },
            {"a\\b\\c",        {"a", "b", "c"}      },
            {".\\a\\b\\c",     {"a", "b", "c"}      },
            {"..\\a\\b\\c",    {"..", "a", "b", "c"}},
            {"a\\..\\a\\b\\c", {"a", "b", "c"}      },
        };
    }

    for (const auto test : cases) {
        EXPECT_EQ(paths::segments(test.path), test.expected);
    }
}
