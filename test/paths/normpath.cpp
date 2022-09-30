#include "../../src/detect.hpp"
#include "../../src/paths.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Paths_Paths, normpath) {
    struct TestCase {
        std::string path;
        std::string expected;
    };

    std::vector<TestCase> cases = {
        {"",         "."       },
        {" ",        " "       },
        {".",        "."       },
        {"..",       ".."      },
        {"a",        "a"       },
        {"/",        "/"       },
        {"/ ",       "/ "      },
        // {"/.",       "/"       },
        // {"/..",      "/"       },
        // {"/a",       "/a"      },
        // {" /",       " "       },
        // {" / ",      " / "     },
        // {" /.",      " "       },
        // {" /..",     "."       },
        // {" /a",      " /a"     },
        // {"./",       "."       },
        // {"./ ",      " "       },
        // {"./.",      "."       },
        // {"./..",     ".."      },
        // {"./a",      "a"       },
        // {"../",      ".."      },
        // {"../ ",     "../ "    },
        // {"../.",     ".."      },
        // {"../..",    "../.."   },
        // {"../a",     "../a"    },
        // {"a/",       "a"       },
        // {"a/ ",      "a/ "     },
        // {"a/.",      "a"       },
        // {"a/..",     "."       },
        // {"a/a",      "a/a"     },
        // {"//",       "//"      },
        // {"// ",      "// "     },
        // {"//.",      "//"      },
        // {"//..",     "//"      },
        // {"//a",      "//a"     },
        // {"/ /",      "/ "      },
        // {"/ / ",     "/ / "    },
        // {"/ /.",     "/ "      },
        // {"/ /..",    "/"       },
        // {"/ /a",     "/ /a"    },
        // {"/./",      "/"       },
        // {"/./ ",     "/ "      },
        // {"/./.",     "/"       },
        // {"/./..",    "/"       },
        // {"/./a",     "/a"      },
        // {"/../",     "/"       },
        // {"/../ ",    "/ "      },
        // {"/../.",    "/"       },
        // {"/../..",   "/"       },
        // {"/../a",    "/a"      },
        // {"/a/",      "/a"      },
        // {"/a/ ",     "/a/ "    },
        // {"/a/.",     "/a"      },
        // {"/a/..",    "/"       },
        // {"/a/a",     "/a/a"    },
        // {" //",      " "       },
        // {" // ",     " / "     },
        // {" //.",     " "       },
        // {" //..",    "."       },
        // {" //a",     " /a"     },
        // {" / /",     " / "     },
        // {" / / ",    " / / "   },
        // {" / /.",    " / "     },
        // {" / /..",   " "       },
        // {" / /a",    " / /a"   },
        // {" /./",     " "       },
        // {" /./ ",    " / "     },
        // {" /./.",    " "       },
        // {" /./..",   "."       },
        // {" /./a",    " /a"     },
        // {" /../",    "."       },
        // {" /../ ",   " "       },
        // {" /../.",   "."       },
        // {" /../..",  ".."      },
        // {" /../a",   "a"       },
        // {" /a/",     " /a"     },
        // {" /a/ ",    " /a/ "   },
        // {" /a/.",    " /a"     },
        // {" /a/..",   " "       },
        // {" /a/a",    " /a/a"   },
        // {".//",      "."       },
        // {".// ",     " "       },
        // {".//.",     "."       },
        // {".//..",    ".."      },
        // {".//a",     "a"       },
        // {"./ /",     " "       },
        // {"./ / ",    " / "     },
        // {"./ /.",    " "       },
        // {"./ /..",   "."       },
        // {"./ /a",    " /a"     },
        // {"././",     "."       },
        // {"././ ",    " "       },
        // {"././.",    "."       },
        // {"././..",   ".."      },
        // {"././a",    "a"       },
        // {"./../",    ".."      },
        // {"./../ ",   "../ "    },
        // {"./../.",   ".."      },
        // {"./../..",  "../.."   },
        // {"./../a",   "../a"    },
        // {"./a/",     "a"       },
        // {"./a/ ",    "a/ "     },
        // {"./a/.",    "a"       },
        // {"./a/..",   "."       },
        // {"./a/a",    "a/a"     },
        // {"..//",     ".."      },
        // {"..// ",    "../ "    },
        // {"..//.",    ".."      },
        // {"..//..",   "../.."   },
        // {"..//a",    "../a"    },
        // {"../ /",    "../ "    },
        // {"../ / ",   "../ / "  },
        // {"../ /.",   "../ "    },
        // {"../ /..",  ".."      },
        // {"../ /a",   "../ /a"  },
        // {".././",    ".."      },
        // {".././ ",   "../ "    },
        // {".././.",   ".."      },
        // {".././..",  "../.."   },
        // {".././a",   "../a"    },
        // {"../../",   "../.."   },
        // {"../../ ",  "../../ " },
        // {"../../.",  "../.."   },
        // {"../../..", "../../.."},
        // {"../../a",  "../../a" },
        // {"../a/",    "../a"    },
        // {"../a/ ",   "../a/ "  },
        // {"../a/.",   "../a"    },
        // {"../a/..",  ".."      },
        // {"../a/a",   "../a/a"  },
        // {"a//",      "a"       },
        // {"a// ",     "a/ "     },
        // {"a//.",     "a"       },
        // {"a//..",    "."       },
        // {"a//a",     "a/a"     },
        // {"a/ /",     "a/ "     },
        // {"a/ / ",    "a/ / "   },
        // {"a/ /.",    "a/ "     },
        // {"a/ /..",   "a"       },
        // {"a/ /a",    "a/ /a"   },
        // {"a/./",     "a"       },
        // {"a/./ ",    "a/ "     },
        // {"a/./.",    "a"       },
        // {"a/./..",   "."       },
        // {"a/./a",    "a/a"     },
        // {"a/../",    "."       },
        // {"a/../ ",   " "       },
        // {"a/../.",   "."       },
        // {"a/../..",  ".."      },
        // {"a/../a",   "a"       },
        // {"a/a/",     "a/a"     },
        // {"a/a/ ",    "a/a/ "   },
        // {"a/a/.",    "a/a"     },
        // {"a/a/..",   "a"       },
        // {"a/a/a",    "a/a/a"   },
    };

    for ( auto test : cases) {
        if (platform::sep == paths::windows_sep) {
            test.path = paths::windows_path(test.path);
            test.expected = paths::windows_path(test.expected);
        }

        EXPECT_EQ(paths::normpath(test.path), test.expected);
    }
};
