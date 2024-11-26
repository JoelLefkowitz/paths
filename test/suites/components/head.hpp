#ifndef PATHS_SUITES_COMPONENTS_HEAD_HPP
#define PATHS_SUITES_COMPONENTS_HEAD_HPP

#include <detect/constants.hpp>
#include <string>
#include <vector>

struct HeadTestCase {
    std::string path;
    std::string expected;
};

const std::vector<HeadTestCase> common_cases = {
    {"",            "." },
    {".",           "." },
    {"..",          ".."},
    {"a",           "a" },
    {"/",           ""  },
    {"/.",          ""  },
    {"/..",         ""  },
    {"/a",          "a" },
    {"./",          "." },
    {"./.",         "." },
    {"./..",        ".."},
    {"./a",         "a" },
    {"../",         ".."},
    {"../.",        ".."},
    {"../..",       ".."},
    {"../a",        "a" },
    {"a/",          "a" },
    {"a/.",         "a" },
    {"a/..",        "." },
    {"a/b",         "b" },
    {"//",          ""  },
    {"//.",         ""  },
    {"//..",        ""  },
    {"//a",         "a" },
    {"/./",         ""  },
    {"/./.",        ""  },
    {"/./..",       ""  },
    {"/./a",        "a" },
    {"/../",        ""  },
    {"/../.",       ""  },
    {"/../..",      ""  },
    {"/../a",       "a" },
    {"/a/",         "a" },
    {"/a/.",        "a" },
    {"/a/..",       ""  },
    {"/a/b",        "b" },
    {".//",         "." },
    {".//.",        "." },
    {".//..",       ".."},
    {".//a",        "a" },
    {"././",        "." },
    {"././.",       "." },
    {"././..",      ".."},
    {"././a",       "a" },
    {"./../",       ".."},
    {"./../.",      ".."},
    {"./../..",     ".."},
    {"./../a",      "a" },
    {"./a/",        "a" },
    {"./a/.",       "a" },
    {"./a/..",      "." },
    {"./a/b",       "b" },
    {"..//",        ".."},
    {"..//.",       ".."},
    {"..//..",      ".."},
    {"..//a",       "a" },
    {".././",       ".."},
    {".././.",      ".."},
    {".././..",     ".."},
    {".././a",      "a" },
    {"../../",      ".."},
    {"../../.",     ".."},
    {"../../..",    ".."},
    {"../../a",     "a" },
    {"../a/",       "a" },
    {"../a/.",      "a" },
    {"../a/..",     ".."},
    {"../a/b",      "b" },
    {"a//",         "a" },
    {"a//.",        "a" },
    {"a//..",       "." },
    {"a//b",        "b" },
    {"a/./",        "a" },
    {"a/./.",       "a" },
    {"a/./..",      "." },
    {"a/./b",       "b" },
    {"a/../",       "." },
    {"a/../.",      "." },
    {"a/../..",     ".."},
    {"a/../b",      "b" },
    {"a/b/",        "b" },
    {"a/b/.",       "b" },
    {"a/b/..",      "a" },
    {"a/b/c",       "c" },
    {"///",         ""  },
    {"///.",        ""  },
    {"///..",       ""  },
    {"///a",        "a" },
    {"//./",        ""  },
    {"//./.",       ""  },
    {"//./..",      ""  },
    {"//./a",       "a" },
    {"//../",       ""  },
    {"//../.",      ""  },
    {"//../..",     ""  },
    {"//../a",      "a" },
    {"//a/",        "a" },
    {"//a/.",       "a" },
    {"//a/..",      ""  },
    {"//a/b",       "b" },
    {"/.//",        ""  },
    {"/.//.",       ""  },
    {"/.//..",      ""  },
    {"/.//a",       "a" },
    {"/././",       ""  },
    {"/././.",      ""  },
    {"/././..",     ""  },
    {"/././a",      "a" },
    {"/./../",      ""  },
    {"/./../.",     ""  },
    {"/./../..",    ""  },
    {"/./../a",     "a" },
    {"/./a/",       "a" },
    {"/./a/.",      "a" },
    {"/./a/..",     ""  },
    {"/./a/b",      "b" },
    {"/..//",       ""  },
    {"/..//.",      ""  },
    {"/..//..",     ""  },
    {"/..//a",      "a" },
    {"/.././",      ""  },
    {"/.././.",     ""  },
    {"/.././..",    ""  },
    {"/.././a",     "a" },
    {"/../../",     ""  },
    {"/../../.",    ""  },
    {"/../../..",   ""  },
    {"/../../a",    "a" },
    {"/../a/",      "a" },
    {"/../a/.",     "a" },
    {"/../a/..",    ""  },
    {"/../a/b",     "b" },
    {"/a//",        "a" },
    {"/a//.",       "a" },
    {"/a//..",      ""  },
    {"/a//b",       "b" },
    {"/a/./",       "a" },
    {"/a/./.",      "a" },
    {"/a/./..",     ""  },
    {"/a/./b",      "b" },
    {"/a/../",      ""  },
    {"/a/../.",     ""  },
    {"/a/../..",    ""  },
    {"/a/../b",     "b" },
    {"/a/b/",       "b" },
    {"/a/b/.",      "b" },
    {"/a/b/..",     "a" },
    {"/a/b/c",      "c" },
    {".///",        "." },
    {".///.",       "." },
    {".///..",      ".."},
    {".///a",       "a" },
    {".//./",       "." },
    {".//./.",      "." },
    {".//./..",     ".."},
    {".//./a",      "a" },
    {".//../",      ".."},
    {".//../.",     ".."},
    {".//../..",    ".."},
    {".//../a",     "a" },
    {".//a/",       "a" },
    {".//a/.",      "a" },
    {".//a/..",     "." },
    {".//a/b",      "b" },
    {"././/",       "." },
    {"././/.",      "." },
    {"././/..",     ".."},
    {"././/a",      "a" },
    {"./././",      "." },
    {"./././.",     "." },
    {"./././..",    ".."},
    {"./././a",     "a" },
    {"././../",     ".."},
    {"././../.",    ".."},
    {"././../..",   ".."},
    {"././../a",    "a" },
    {"././a/",      "a" },
    {"././a/.",     "a" },
    {"././a/..",    "." },
    {"././a/b",     "b" },
    {"./..//",      ".."},
    {"./..//.",     ".."},
    {"./..//..",    ".."},
    {"./..//a",     "a" },
    {"./.././",     ".."},
    {"./.././.",    ".."},
    {"./.././..",   ".."},
    {"./.././a",    "a" },
    {"./../../",    ".."},
    {"./../../.",   ".."},
    {"./../../..",  ".."},
    {"./../../a",   "a" },
    {"./../a/",     "a" },
    {"./../a/.",    "a" },
    {"./../a/..",   ".."},
    {"./../a/b",    "b" },
    {"./a//",       "a" },
    {"./a//.",      "a" },
    {"./a//..",     "." },
    {"./a//b",      "b" },
    {"./a/./",      "a" },
    {"./a/./.",     "a" },
    {"./a/./..",    "." },
    {"./a/./b",     "b" },
    {"./a/../",     "." },
    {"./a/../.",    "." },
    {"./a/../..",   ".."},
    {"./a/../b",    "b" },
    {"./a/b/",      "b" },
    {"./a/b/.",     "b" },
    {"./a/b/..",    "a" },
    {"./a/b/c",     "c" },
    {"..///",       ".."},
    {"..///.",      ".."},
    {"..///..",     ".."},
    {"..///a",      "a" },
    {"..//./",      ".."},
    {"..//./.",     ".."},
    {"..//./..",    ".."},
    {"..//./a",     "a" },
    {"..//../",     ".."},
    {"..//../.",    ".."},
    {"..//../..",   ".."},
    {"..//../a",    "a" },
    {"..//a/",      "a" },
    {"..//a/.",     "a" },
    {"..//a/..",    ".."},
    {"..//a/b",     "b" },
    {".././/",      ".."},
    {".././/.",     ".."},
    {".././/..",    ".."},
    {".././/a",     "a" },
    {"../././",     ".."},
    {"../././.",    ".."},
    {"../././..",   ".."},
    {"../././a",    "a" },
    {".././../",    ".."},
    {".././../.",   ".."},
    {".././../..",  ".."},
    {".././../a",   "a" },
    {".././a/",     "a" },
    {".././a/.",    "a" },
    {".././a/..",   ".."},
    {".././a/b",    "b" },
    {"../..//",     ".."},
    {"../..//.",    ".."},
    {"../..//..",   ".."},
    {"../..//a",    "a" },
    {"../.././",    ".."},
    {"../.././.",   ".."},
    {"../.././..",  ".."},
    {"../.././a",   "a" },
    {"../../../",   ".."},
    {"../../../.",  ".."},
    {"../../../..", ".."},
    {"../../../a",  "a" },
    {"../../a/",    "a" },
    {"../../a/.",   "a" },
    {"../../a/..",  ".."},
    {"../../a/b",   "b" },
    {"../a//",      "a" },
    {"../a//.",     "a" },
    {"../a//..",    ".."},
    {"../a//b",     "b" },
    {"../a/./",     "a" },
    {"../a/./.",    "a" },
    {"../a/./..",   ".."},
    {"../a/./b",    "b" },
    {"../a/../",    ".."},
    {"../a/../.",   ".."},
    {"../a/../..",  ".."},
    {"../a/../b",   "b" },
    {"../a/b/",     "b" },
    {"../a/b/.",    "b" },
    {"../a/b/..",   "a" },
    {"../a/b/c",    "c" },
    {"a///",        "a" },
    {"a///.",       "a" },
    {"a///..",      "." },
    {"a///b",       "b" },
    {"a//./",       "a" },
    {"a//./.",      "a" },
    {"a//./..",     "." },
    {"a//./b",      "b" },
    {"a//../",      "." },
    {"a//../.",     "." },
    {"a//../..",    ".."},
    {"a//../b",     "b" },
    {"a//b/",       "b" },
    {"a//b/.",      "b" },
    {"a//b/..",     "a" },
    {"a//b/c",      "c" },
    {"a/.//",       "a" },
    {"a/.//.",      "a" },
    {"a/.//..",     "." },
    {"a/.//b",      "b" },
    {"a/././",      "a" },
    {"a/././.",     "a" },
    {"a/././..",    "." },
    {"a/././b",     "b" },
    {"a/./../",     "." },
    {"a/./../.",    "." },
    {"a/./../..",   ".."},
    {"a/./../b",    "b" },
    {"a/./b/",      "b" },
    {"a/./b/.",     "b" },
    {"a/./b/..",    "a" },
    {"a/./b/c",     "c" },
    {"a/..//",      "." },
    {"a/..//.",     "." },
    {"a/..//..",    ".."},
    {"a/..//b",     "b" },
    {"a/.././",     "." },
    {"a/.././.",    "." },
    {"a/.././..",   ".."},
    {"a/.././b",    "b" },
    {"a/../../",    ".."},
    {"a/../../.",   ".."},
    {"a/../../..",  ".."},
    {"a/../../b",   "b" },
    {"a/../b/",     "b" },
    {"a/../b/.",    "b" },
    {"a/../b/..",   "." },
    {"a/../b/c",    "c" },
    {"a/b//",       "b" },
    {"a/b//.",      "b" },
    {"a/b//..",     "a" },
    {"a/b//c",      "c" },
    {"a/b/./",      "b" },
    {"a/b/./.",     "b" },
    {"a/b/./..",    "a" },
    {"a/b/./c",     "c" },
    {"a/b/../",     "a" },
    {"a/b/../.",    "a" },
    {"a/b/../..",   "." },
    {"a/b/../c",    "c" },
    {"a/b/c/",      "c" },
    {"a/b/c/.",     "c" },
    {"a/b/c/..",    "b" },
    {"a/b/c/d",     "d" },
};

const std::vector<HeadTestCase> windows_cases = {
    {"C:",    "" },
    {"//a/b", "b"},
};

const std::vector<HeadTestCase> posix_cases = {
    {"C:",    "C:"},
    {"//a/b", "b" },
};

const std::vector<HeadTestCase> platform_cases = platform::os == platform::Windows ? windows_cases : posix_cases;

#endif
