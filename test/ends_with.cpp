#include "../src/strings.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Paths_Strings, ends_with) {
    struct TestCase {
        std::string str;
        std::string prefix;
    };

    std::vector<TestCase> true_cases = {
        {"",    ""   },
        {" ",   ""   },
        {" ",   " "  },
        {".",   ""   },
        {".",   "."  },
        {"a",   ""   },
        {"a",   "a"  },
        {"  ",  " "  },
        {"..",  "."  },
        {"aa",  "a"  },
        {"a ",  " "  },
        {" a",  "a"  },
        {"aa",  "aa" },
        {"a ",  "a " },
        {" a",  " a" },
        {"aaa", "a"  },
        {"a a", "a"  },
        {"a b", "b"  },
        {"aaa", "aa" },
        {"a a", " a" },
        {"a b", " b" },
        {"aaa", "aaa"},
        {"a a", "a a"},
        {"a b", "a b"},
    };

    std::vector<TestCase> false_cases = {
        {"",  " " },
        {" ", "  "},
        {"a", "b" },
        {"a", "aa"},
    };
    for (const auto test : true_cases) {
        EXPECT_TRUE(paths::ends_with(test.str, test.prefix));
    }

    for (const auto test : false_cases) {
        EXPECT_FALSE(paths::ends_with(test.str, test.prefix));
    }
}
