#ifndef PATHS_SUITES_COMPONENTS_TAIL_HPP
#define PATHS_SUITES_COMPONENTS_TAIL_HPP

#include <string>
#include <vector>

// cppclean-disable-next-line
#include "../../../src/detect.hpp"

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
    {"C:",    ""   },
    {"//a/b", "//a"},
};

const std::vector<TailTestCase> platform_cases = platform::os == platform::Windows ? windows_cases : posix_cases;

#endif
