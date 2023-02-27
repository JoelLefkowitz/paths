#ifndef TEST_PATHS_JOIN_H
#define TEST_PATHS_JOIN_H

#include <string>
#include <vector>

struct JoinTestCase {
    std::vector<std::string> strs;
    std::string              delimiter;
    std::string              expected;
};

const std::vector<JoinTestCase> cases = {
    {{},              "",   ""       },
    {{},              "-",  ""       },
    {{},              "--", ""       },
    {{""},            "",   ""       },
    {{""},            "-",  ""       },
    {{""},            "--", ""       },
    {{"a"},           "",   "a"      },
    {{"a"},           "-",  "a"      },
    {{"a"},           "--", "a"      },
    {{"a", "b"},      "",   "ab"     },
    {{"a", "b"},      "-",  "a-b"    },
    {{"a", "b"},      "--", "a--b"   },
    {{"a", "b", "c"}, "",   "abc"    },
    {{"a", "b", "c"}, "-",  "a-b-c"  },
    {{"a", "b", "c"}, "--", "a--b--c"},
};

#endif
