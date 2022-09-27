#include "../src/strings.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Paths_Strings, join) {
    struct TestCase {
        std::vector<std::string> strs;
        std::string              delimiter;
        std::string              expected;
    };

    std::vector<TestCase> cases = {
        {{""},               "",  ""        },
        {{" "},              "",  " "       },
        {{"."},              "",  "."       },
        {{".."},             "",  ".."      },
        {{"a"},              "",  "a"       },
        {{"", ""},           "",  ""        },
        {{" ", " "},         "",  "  "      },
        {{"a", "a"},         "",  "aa"      },
        {{""},               "/", ""        },
        {{" "},              "/", " "       },
        {{"."},              "/", "."       },
        {{".."},             "/", ".."      },
        {{"a"},              "/", "a"       },
        {{"", ""},           "/", "/"       },
        {{"", " "},          "/", "/ "      },
        {{"", "."},          "/", "/."      },
        {{"", ".."},         "/", "/.."     },
        {{"", "a"},          "/", "/a"      },
        {{" ", ""},          "/", " /"      },
        {{" ", " "},         "/", " / "     },
        {{" ", "."},         "/", " /."     },
        {{" ", ".."},        "/", " /.."    },
        {{" ", "a"},         "/", " /a"     },
        {{".", ""},          "/", "./"      },
        {{".", " "},         "/", "./ "     },
        {{".", "."},         "/", "./."     },
        {{".", ".."},        "/", "./.."    },
        {{".", "a"},         "/", "./a"     },
        {{"..", ""},         "/", "../"     },
        {{"..", " "},        "/", "../ "    },
        {{"..", "."},        "/", "../."    },
        {{"..", ".."},       "/", "../.."   },
        {{"..", "a"},        "/", "../a"    },
        {{"a", ""},          "/", "a/"      },
        {{"a", " "},         "/", "a/ "     },
        {{"a", "."},         "/", "a/."     },
        {{"a", ".."},        "/", "a/.."    },
        {{"a", "a"},         "/", "a/a"     },
        {{"", "", ""},       "/", "//"      },
        {{"", "", " "},      "/", "// "     },
        {{"", "", "."},      "/", "//."     },
        {{"", "", ".."},     "/", "//.."    },
        {{"", "", "a"},      "/", "//a"     },
        {{"", " ", ""},      "/", "/ /"     },
        {{"", " ", " "},     "/", "/ / "    },
        {{"", " ", "."},     "/", "/ /."    },
        {{"", " ", ".."},    "/", "/ /.."   },
        {{"", " ", "a"},     "/", "/ /a"    },
        {{"", ".", ""},      "/", "/./"     },
        {{"", ".", " "},     "/", "/./ "    },
        {{"", ".", "."},     "/", "/./."    },
        {{"", ".", ".."},    "/", "/./.."   },
        {{"", ".", "a"},     "/", "/./a"    },
        {{"", "..", ""},     "/", "/../"    },
        {{"", "..", " "},    "/", "/../ "   },
        {{"", "..", "."},    "/", "/../."   },
        {{"", "..", ".."},   "/", "/../.."  },
        {{"", "..", "a"},    "/", "/../a"   },
        {{"", "a", ""},      "/", "/a/"     },
        {{"", "a", " "},     "/", "/a/ "    },
        {{"", "a", "."},     "/", "/a/."    },
        {{"", "a", ".."},    "/", "/a/.."   },
        {{"", "a", "a"},     "/", "/a/a"    },
        {{" ", "", ""},      "/", " //"     },
        {{" ", "", " "},     "/", " // "    },
        {{" ", "", "."},     "/", " //."    },
        {{" ", "", ".."},    "/", " //.."   },
        {{" ", "", "a"},     "/", " //a"    },
        {{" ", " ", ""},     "/", " / /"    },
        {{" ", " ", " "},    "/", " / / "   },
        {{" ", " ", "."},    "/", " / /."   },
        {{" ", " ", ".."},   "/", " / /.."  },
        {{" ", " ", "a"},    "/", " / /a"   },
        {{" ", ".", ""},     "/", " /./"    },
        {{" ", ".", " "},    "/", " /./ "   },
        {{" ", ".", "."},    "/", " /./."   },
        {{" ", ".", ".."},   "/", " /./.."  },
        {{" ", ".", "a"},    "/", " /./a"   },
        {{" ", "..", ""},    "/", " /../"   },
        {{" ", "..", " "},   "/", " /../ "  },
        {{" ", "..", "."},   "/", " /../."  },
        {{" ", "..", ".."},  "/", " /../.." },
        {{" ", "..", "a"},   "/", " /../a"  },
        {{" ", "a", ""},     "/", " /a/"    },
        {{" ", "a", " "},    "/", " /a/ "   },
        {{" ", "a", "."},    "/", " /a/."   },
        {{" ", "a", ".."},   "/", " /a/.."  },
        {{" ", "a", "a"},    "/", " /a/a"   },
        {{".", "", ""},      "/", ".//"     },
        {{".", "", " "},     "/", ".// "    },
        {{".", "", "."},     "/", ".//."    },
        {{".", "", ".."},    "/", ".//.."   },
        {{".", "", "a"},     "/", ".//a"    },
        {{".", " ", ""},     "/", "./ /"    },
        {{".", " ", " "},    "/", "./ / "   },
        {{".", " ", "."},    "/", "./ /."   },
        {{".", " ", ".."},   "/", "./ /.."  },
        {{".", " ", "a"},    "/", "./ /a"   },
        {{".", ".", ""},     "/", "././"    },
        {{".", ".", " "},    "/", "././ "   },
        {{".", ".", "."},    "/", "././."   },
        {{".", ".", ".."},   "/", "././.."  },
        {{".", ".", "a"},    "/", "././a"   },
        {{".", "..", ""},    "/", "./../"   },
        {{".", "..", " "},   "/", "./../ "  },
        {{".", "..", "."},   "/", "./../."  },
        {{".", "..", ".."},  "/", "./../.." },
        {{".", "..", "a"},   "/", "./../a"  },
        {{".", "a", ""},     "/", "./a/"    },
        {{".", "a", " "},    "/", "./a/ "   },
        {{".", "a", "."},    "/", "./a/."   },
        {{".", "a", ".."},   "/", "./a/.."  },
        {{".", "a", "a"},    "/", "./a/a"   },
        {{"..", "", ""},     "/", "..//"    },
        {{"..", "", " "},    "/", "..// "   },
        {{"..", "", "."},    "/", "..//."   },
        {{"..", "", ".."},   "/", "..//.."  },
        {{"..", "", "a"},    "/", "..//a"   },
        {{"..", " ", ""},    "/", "../ /"   },
        {{"..", " ", " "},   "/", "../ / "  },
        {{"..", " ", "."},   "/", "../ /."  },
        {{"..", " ", ".."},  "/", "../ /.." },
        {{"..", " ", "a"},   "/", "../ /a"  },
        {{"..", ".", ""},    "/", ".././"   },
        {{"..", ".", " "},   "/", ".././ "  },
        {{"..", ".", "."},   "/", ".././."  },
        {{"..", ".", ".."},  "/", ".././.." },
        {{"..", ".", "a"},   "/", ".././a"  },
        {{"..", "..", ""},   "/", "../../"  },
        {{"..", "..", " "},  "/", "../../ " },
        {{"..", "..", "."},  "/", "../../." },
        {{"..", "..", ".."}, "/", "../../.."},
        {{"..", "..", "a"},  "/", "../../a" },
        {{"..", "a", ""},    "/", "../a/"   },
        {{"..", "a", " "},   "/", "../a/ "  },
        {{"..", "a", "."},   "/", "../a/."  },
        {{"..", "a", ".."},  "/", "../a/.." },
        {{"..", "a", "a"},   "/", "../a/a"  },
        {{"a", "", ""},      "/", "a//"     },
        {{"a", "", " "},     "/", "a// "    },
        {{"a", "", "."},     "/", "a//."    },
        {{"a", "", ".."},    "/", "a//.."   },
        {{"a", "", "a"},     "/", "a//a"    },
        {{"a", " ", ""},     "/", "a/ /"    },
        {{"a", " ", " "},    "/", "a/ / "   },
        {{"a", " ", "."},    "/", "a/ /."   },
        {{"a", " ", ".."},   "/", "a/ /.."  },
        {{"a", " ", "a"},    "/", "a/ /a"   },
        {{"a", ".", ""},     "/", "a/./"    },
        {{"a", ".", " "},    "/", "a/./ "   },
        {{"a", ".", "."},    "/", "a/./."   },
        {{"a", ".", ".."},   "/", "a/./.."  },
        {{"a", ".", "a"},    "/", "a/./a"   },
        {{"a", "..", ""},    "/", "a/../"   },
        {{"a", "..", " "},   "/", "a/../ "  },
        {{"a", "..", "."},   "/", "a/../."  },
        {{"a", "..", ".."},  "/", "a/../.." },
        {{"a", "..", "a"},   "/", "a/../a"  },
        {{"a", "a", ""},     "/", "a/a/"    },
        {{"a", "a", " "},    "/", "a/a/ "   },
        {{"a", "a", "."},    "/", "a/a/."   },
        {{"a", "a", ".."},   "/", "a/a/.."  },
        {{"a", "a", "a"},    "/", "a/a/a"   },
    };

    for (const auto test : cases) {
        EXPECT_EQ(paths::join(test.strs, test.delimiter), test.expected);
    }
}
