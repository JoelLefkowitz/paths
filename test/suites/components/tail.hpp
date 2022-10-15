#ifndef TEST_PATHS_TAIL_H
#define TEST_PATHS_TAIL_H

#include <string>
#include <vector>

struct TailTestCase {
    std::string path;
    std::string expected;
};

const std::vector<TailTestCase> common_cases = {
    {"",            ""        },
    {".",           ""        },
    {"..",          ""        },
    {"a",           ""        },
    {"/",           "/"       },
    {"/.",          "/"       },
    {"/..",         "/"       },
    {"/a",          "/"       },
    {"./",          ""        },
    {"./.",         ""        },
    {"./..",        ""        },
    {"./a",         ""        },
    {"../",         ""        },
    {"../.",        ""        },
    {"../..",       ".."      },
    {"../a",        ".."      },
    {"a/",          ""        },
    {"a/.",         ""        },
    {"a/..",        ""        },
    {"a/b",         "a"       },
    {"//",          "//"      },
    {"//.",         "//"      },
    {"//..",        "//"      },
    {"//a",         "//"      },
    {"/./",         "/"       },
    {"/./.",        "/"       },
    {"/./..",       "/"       },
    {"/./a",        "/"       },
    {"/../",        "/"       },
    {"/../.",       "/"       },
    {"/../..",      "/"       },
    {"/../a",       "/"       },
    {"/a/",         "/"       },
    {"/a/.",        "/"       },
    {"/a/..",       "/"       },
    {"/a/b",        "/a"      },
    {".//",         ""        },
    {".//.",        ""        },
    {".//..",       ""        },
    {".//a",        ""        },
    {"././",        ""        },
    {"././.",       ""        },
    {"././..",      ""        },
    {"././a",       ""        },
    {"./../",       ""        },
    {"./../.",      ""        },
    {"./../..",     ".."      },
    {"./../a",      ".."      },
    {"./a/",        ""        },
    {"./a/.",       ""        },
    {"./a/..",      ""        },
    {"./a/b",       "a"       },
    {"..//",        ""        },
    {"..//.",       ""        },
    {"..//..",      ".."      },
    {"..//a",       ".."      },
    {".././",       ""        },
    {".././.",      ""        },
    {".././..",     ".."      },
    {".././a",      ".."      },
    {"../../",      ".."      },
    {"../../.",     ".."      },
    {"../../..",    "../.."   },
    {"../../a",     "../.."   },
    {"../a/",       ".."      },
    {"../a/.",      ".."      },
    {"../a/..",     ""        },
    {"../a/b",      "../a"    },
    {"a//",         ""        },
    {"a//.",        ""        },
    {"a//..",       ""        },
    {"a//b",        "a"       },
    {"a/./",        ""        },
    {"a/./.",       ""        },
    {"a/./..",      ""        },
    {"a/./b",       "a"       },
    {"a/../",       ""        },
    {"a/../.",      ""        },
    {"a/../..",     ""        },
    {"a/../b",      ""        },
    {"a/b/",        "a"       },
    {"a/b/.",       "a"       },
    {"a/b/..",      ""        },
    {"a/b/c",       "a/b"     },
    {"///",         "/"       },
    {"///.",        "/"       },
    {"///..",       "/"       },
    {"///a",        "/"       },
    {"//./",        "//"      },
    {"//./.",       "//"      },
    {"//./..",      "//"      },
    {"//./a",       "//"      },
    {"//../",       "//"      },
    {"//../.",      "//"      },
    {"//../..",     "//"      },
    {"//../a",      "//"      },
    {"//a/",        "//"      },
    {"//a/.",       "//"      },
    {"//a/..",      "//"      },
    {"//a/b",       "//a"     },
    {"/.//",        "/"       },
    {"/.//.",       "/"       },
    {"/.//..",      "/"       },
    {"/.//a",       "/"       },
    {"/././",       "/"       },
    {"/././.",      "/"       },
    {"/././..",     "/"       },
    {"/././a",      "/"       },
    {"/./../",      "/"       },
    {"/./../.",     "/"       },
    {"/./../..",    "/"       },
    {"/./../a",     "/"       },
    {"/./a/",       "/"       },
    {"/./a/.",      "/"       },
    {"/./a/..",     "/"       },
    {"/./a/b",      "/a"      },
    {"/..//",       "/"       },
    {"/..//.",      "/"       },
    {"/..//..",     "/"       },
    {"/..//a",      "/"       },
    {"/.././",      "/"       },
    {"/.././.",     "/"       },
    {"/.././..",    "/"       },
    {"/.././a",     "/"       },
    {"/../../",     "/"       },
    {"/../../.",    "/"       },
    {"/../../..",   "/"       },
    {"/../../a",    "/"       },
    {"/../a/",      "/"       },
    {"/../a/.",     "/"       },
    {"/../a/..",    "/"       },
    {"/../a/b",     "/a"      },
    {"/a//",        "/"       },
    {"/a//.",       "/"       },
    {"/a//..",      "/"       },
    {"/a//b",       "/a"      },
    {"/a/./",       "/"       },
    {"/a/./.",      "/"       },
    {"/a/./..",     "/"       },
    {"/a/./b",      "/a"      },
    {"/a/../",      "/"       },
    {"/a/../.",     "/"       },
    {"/a/../..",    "/"       },
    {"/a/../b",     "/"       },
    {"/a/b/",       "/a"      },
    {"/a/b/.",      "/a"      },
    {"/a/b/..",     "/"       },
    {"/a/b/c",      "/a/b"    },
    {".///",        ""        },
    {".///.",       ""        },
    {".///..",      ""        },
    {".///a",       ""        },
    {".//./",       ""        },
    {".//./.",      ""        },
    {".//./..",     ""        },
    {".//./a",      ""        },
    {".//../",      ""        },
    {".//../.",     ""        },
    {".//../..",    ".."      },
    {".//../a",     ".."      },
    {".//a/",       ""        },
    {".//a/.",      ""        },
    {".//a/..",     ""        },
    {".//a/b",      "a"       },
    {"././/",       ""        },
    {"././/.",      ""        },
    {"././/..",     ""        },
    {"././/a",      ""        },
    {"./././",      ""        },
    {"./././.",     ""        },
    {"./././..",    ""        },
    {"./././a",     ""        },
    {"././../",     ""        },
    {"././../.",    ""        },
    {"././../..",   ".."      },
    {"././../a",    ".."      },
    {"././a/",      ""        },
    {"././a/.",     ""        },
    {"././a/..",    ""        },
    {"././a/b",     "a"       },
    {"./..//",      ""        },
    {"./..//.",     ""        },
    {"./..//..",    ".."      },
    {"./..//a",     ".."      },
    {"./.././",     ""        },
    {"./.././.",    ""        },
    {"./.././..",   ".."      },
    {"./.././a",    ".."      },
    {"./../../",    ".."      },
    {"./../../.",   ".."      },
    {"./../../..",  "../.."   },
    {"./../../a",   "../.."   },
    {"./../a/",     ".."      },
    {"./../a/.",    ".."      },
    {"./../a/..",   ""        },
    {"./../a/b",    "../a"    },
    {"./a//",       ""        },
    {"./a//.",      ""        },
    {"./a//..",     ""        },
    {"./a//b",      "a"       },
    {"./a/./",      ""        },
    {"./a/./.",     ""        },
    {"./a/./..",    ""        },
    {"./a/./b",     "a"       },
    {"./a/../",     ""        },
    {"./a/../.",    ""        },
    {"./a/../..",   ""        },
    {"./a/../b",    ""        },
    {"./a/b/",      "a"       },
    {"./a/b/.",     "a"       },
    {"./a/b/..",    ""        },
    {"./a/b/c",     "a/b"     },
    {"..///",       ""        },
    {"..///.",      ""        },
    {"..///..",     ".."      },
    {"..///a",      ".."      },
    {"..//./",      ""        },
    {"..//./.",     ""        },
    {"..//./..",    ".."      },
    {"..//./a",     ".."      },
    {"..//../",     ".."      },
    {"..//../.",    ".."      },
    {"..//../..",   "../.."   },
    {"..//../a",    "../.."   },
    {"..//a/",      ".."      },
    {"..//a/.",     ".."      },
    {"..//a/..",    ""        },
    {"..//a/b",     "../a"    },
    {".././/",      ""        },
    {".././/.",     ""        },
    {".././/..",    ".."      },
    {".././/a",     ".."      },
    {"../././",     ""        },
    {"../././.",    ""        },
    {"../././..",   ".."      },
    {"../././a",    ".."      },
    {".././../",    ".."      },
    {".././../.",   ".."      },
    {".././../..",  "../.."   },
    {".././../a",   "../.."   },
    {".././a/",     ".."      },
    {".././a/.",    ".."      },
    {".././a/..",   ""        },
    {".././a/b",    "../a"    },
    {"../..//",     ".."      },
    {"../..//.",    ".."      },
    {"../..//..",   "../.."   },
    {"../..//a",    "../.."   },
    {"../.././",    ".."      },
    {"../.././.",   ".."      },
    {"../.././..",  "../.."   },
    {"../.././a",   "../.."   },
    {"../../../",   "../.."   },
    {"../../../.",  "../.."   },
    {"../../../..", "../../.."},
    {"../../../a",  "../../.."},
    {"../../a/",    "../.."   },
    {"../../a/.",   "../.."   },
    {"../../a/..",  ".."      },
    {"../../a/b",   "../../a" },
    {"../a//",      ".."      },
    {"../a//.",     ".."      },
    {"../a//..",    ""        },
    {"../a//b",     "../a"    },
    {"../a/./",     ".."      },
    {"../a/./.",    ".."      },
    {"../a/./..",   ""        },
    {"../a/./b",    "../a"    },
    {"../a/../",    ""        },
    {"../a/../.",   ""        },
    {"../a/../..",  ".."      },
    {"../a/../b",   ".."      },
    {"../a/b/",     "../a"    },
    {"../a/b/.",    "../a"    },
    {"../a/b/..",   ".."      },
    {"../a/b/c",    "../a/b"  },
    {"a///",        ""        },
    {"a///.",       ""        },
    {"a///..",      ""        },
    {"a///b",       "a"       },
    {"a//./",       ""        },
    {"a//./.",      ""        },
    {"a//./..",     ""        },
    {"a//./b",      "a"       },
    {"a//../",      ""        },
    {"a//../.",     ""        },
    {"a//../..",    ""        },
    {"a//../b",     ""        },
    {"a//b/",       "a"       },
    {"a//b/.",      "a"       },
    {"a//b/..",     ""        },
    {"a//b/c",      "a/b"     },
    {"a/.//",       ""        },
    {"a/.//.",      ""        },
    {"a/.//..",     ""        },
    {"a/.//b",      "a"       },
    {"a/././",      ""        },
    {"a/././.",     ""        },
    {"a/././..",    ""        },
    {"a/././b",     "a"       },
    {"a/./../",     ""        },
    {"a/./../.",    ""        },
    {"a/./../..",   ""        },
    {"a/./../b",    ""        },
    {"a/./b/",      "a"       },
    {"a/./b/.",     "a"       },
    {"a/./b/..",    ""        },
    {"a/./b/c",     "a/b"     },
    {"a/..//",      ""        },
    {"a/..//.",     ""        },
    {"a/..//..",    ""        },
    {"a/..//b",     ""        },
    {"a/.././",     ""        },
    {"a/.././.",    ""        },
    {"a/.././..",   ""        },
    {"a/.././b",    ""        },
    {"a/../../",    ""        },
    {"a/../../.",   ""        },
    {"a/../../..",  ".."      },
    {"a/../../b",   ".."      },
    {"a/../b/",     ""        },
    {"a/../b/.",    ""        },
    {"a/../b/..",   ""        },
    {"a/../b/c",    "b"       },
    {"a/b//",       "a"       },
    {"a/b//.",      "a"       },
    {"a/b//..",     ""        },
    {"a/b//c",      "a/b"     },
    {"a/b/./",      "a"       },
    {"a/b/./.",     "a"       },
    {"a/b/./..",    ""        },
    {"a/b/./c",     "a/b"     },
    {"a/b/../",     ""        },
    {"a/b/../.",    ""        },
    {"a/b/../..",   ""        },
    {"a/b/../c",    "a"       },
    {"a/b/c/",      "a/b"     },
    {"a/b/c/.",     "a/b"     },
    {"a/b/c/..",    "a"       },
    {"a/b/c/d",     "a/b/c"   },
};

const std::vector<TailTestCase> windows_cases = {
    {"C:",      ""     },
    {"//a/b",   "//a/b"},
    {"//a/b/c", "//a/b"},
};

const std::vector<TailTestCase> posix_cases = {
    {"C:",    ""     },
    {"//a/b", "//a"  },
    {"//a/b", "//a/b"},
};

#endif