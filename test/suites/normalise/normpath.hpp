#ifndef TEST_PATHS_NORMPATH_H
#define TEST_PATHS_NORMPATH_H

#include <string>
#include <vector>

// cppclean-disable-next-line
#include "../../../src/detect.hpp"

struct NormpathTestCase {
    std::string path;
    std::string expected;
};

const std::vector<NormpathTestCase> common_cases = {
    {"",               "."             },
    {".",              "."             },
    {"..",             ".."            },
    {"a",              "a"             },
    {"/",              "/"             },
    {"/.",             "/"             },
    {"/..",            "/"             },
    {"/a",             "/a"            },
    {"./",             "."             },
    {"./.",            "."             },
    {"./..",           ".."            },
    {"./a",            "a"             },
    {"../",            ".."            },
    {"../.",           ".."            },
    {"../..",          "../.."         },
    {"../a",           "../a"          },
    {"a/",             "a"             },
    {"a/.",            "a"             },
    {"a/..",           "."             },
    {"a/b",            "a/b"           },
    {"//",             "//"            },
    {"//.",            "//"            },
    {"//..",           "//"            },
    {"//a",            "//a"           },
    {"/./",            "/"             },
    {"/./.",           "/"             },
    {"/./..",          "/"             },
    {"/./a",           "/a"            },
    {"/../",           "/"             },
    {"/../.",          "/"             },
    {"/../..",         "/"             },
    {"/../a",          "/a"            },
    {"/a/",            "/a"            },
    {"/a/.",           "/a"            },
    {"/a/..",          "/"             },
    {"/a/b",           "/a/b"          },
    {".//",            "."             },
    {".//.",           "."             },
    {".//..",          ".."            },
    {".//a",           "a"             },
    {"././",           "."             },
    {"././.",          "."             },
    {"././..",         ".."            },
    {"././a",          "a"             },
    {"./../",          ".."            },
    {"./../.",         ".."            },
    {"./../..",        "../.."         },
    {"./../a",         "../a"          },
    {"./a/",           "a"             },
    {"./a/.",          "a"             },
    {"./a/..",         "."             },
    {"./a/b",          "a/b"           },
    {"..//",           ".."            },
    {"..//.",          ".."            },
    {"..//..",         "../.."         },
    {"..//a",          "../a"          },
    {".././",          ".."            },
    {".././.",         ".."            },
    {".././..",        "../.."         },
    {".././a",         "../a"          },
    {"../../",         "../.."         },
    {"../../.",        "../.."         },
    {"../../..",       "../../.."      },
    {"../../a",        "../../a"       },
    {"../a/",          "../a"          },
    {"../a/.",         "../a"          },
    {"../a/..",        ".."            },
    {"../a/b",         "../a/b"        },
    {"a//",            "a"             },
    {"a//.",           "a"             },
    {"a//..",          "."             },
    {"a//b",           "a/b"           },
    {"a/./",           "a"             },
    {"a/./.",          "a"             },
    {"a/./..",         "."             },
    {"a/./b",          "a/b"           },
    {"a/../",          "."             },
    {"a/../.",         "."             },
    {"a/../..",        ".."            },
    {"a/../b",         "b"             },
    {"a/b/",           "a/b"           },
    {"a/b/.",          "a/b"           },
    {"a/b/..",         "a"             },
    {"a/b/c",          "a/b/c"         },
    {"///",            "/"             },
    {"///.",           "/"             },
    {"///..",          "/"             },
    {"///a",           "/a"            },
    {"//./",           "//"            },
    {"//./.",          "//"            },
    {"//./..",         "//"            },
    {"//./a",          "//a"           },
    {"//../",          "//"            },
    {"//../.",         "//"            },
    {"//../..",        "//"            },
    {"//../a",         "//a"           },
    {"//a/",           "//a"           },
    {"//a/.",          "//a"           },
    {"//a/..",         "//"            },
    {"//a/b",          "//a/b"         },
    {"/.//",           "/"             },
    {"/.//.",          "/"             },
    {"/.//..",         "/"             },
    {"/.//a",          "/a"            },
    {"/././",          "/"             },
    {"/././.",         "/"             },
    {"/././..",        "/"             },
    {"/././a",         "/a"            },
    {"/./../",         "/"             },
    {"/./../.",        "/"             },
    {"/./../..",       "/"             },
    {"/./../a",        "/a"            },
    {"/./a/",          "/a"            },
    {"/./a/.",         "/a"            },
    {"/./a/..",        "/"             },
    {"/./a/b",         "/a/b"          },
    {"/..//",          "/"             },
    {"/..//.",         "/"             },
    {"/..//..",        "/"             },
    {"/..//a",         "/a"            },
    {"/.././",         "/"             },
    {"/.././.",        "/"             },
    {"/.././..",       "/"             },
    {"/.././a",        "/a"            },
    {"/../../",        "/"             },
    {"/../../.",       "/"             },
    {"/../../..",      "/"             },
    {"/../../a",       "/a"            },
    {"/../a/",         "/a"            },
    {"/../a/.",        "/a"            },
    {"/../a/..",       "/"             },
    {"/../a/b",        "/a/b"          },
    {"/a//",           "/a"            },
    {"/a//.",          "/a"            },
    {"/a//..",         "/"             },
    {"/a//b",          "/a/b"          },
    {"/a/./",          "/a"            },
    {"/a/./.",         "/a"            },
    {"/a/./..",        "/"             },
    {"/a/./b",         "/a/b"          },
    {"/a/../",         "/"             },
    {"/a/../.",        "/"             },
    {"/a/../..",       "/"             },
    {"/a/../b",        "/b"            },
    {"/a/b/",          "/a/b"          },
    {"/a/b/.",         "/a/b"          },
    {"/a/b/..",        "/a"            },
    {"/a/b/c",         "/a/b/c"        },
    {".///",           "."             },
    {".///.",          "."             },
    {".///..",         ".."            },
    {".///a",          "a"             },
    {".//./",          "."             },
    {".//./.",         "."             },
    {".//./..",        ".."            },
    {".//./a",         "a"             },
    {".//../",         ".."            },
    {".//../.",        ".."            },
    {".//../..",       "../.."         },
    {".//../a",        "../a"          },
    {".//a/",          "a"             },
    {".//a/.",         "a"             },
    {".//a/..",        "."             },
    {".//a/b",         "a/b"           },
    {"././/",          "."             },
    {"././/.",         "."             },
    {"././/..",        ".."            },
    {"././/a",         "a"             },
    {"./././",         "."             },
    {"./././.",        "."             },
    {"./././..",       ".."            },
    {"./././a",        "a"             },
    {"././../",        ".."            },
    {"././../.",       ".."            },
    {"././../..",      "../.."         },
    {"././../a",       "../a"          },
    {"././a/",         "a"             },
    {"././a/.",        "a"             },
    {"././a/..",       "."             },
    {"././a/b",        "a/b"           },
    {"./..//",         ".."            },
    {"./..//.",        ".."            },
    {"./..//..",       "../.."         },
    {"./..//a",        "../a"          },
    {"./.././",        ".."            },
    {"./.././.",       ".."            },
    {"./.././..",      "../.."         },
    {"./.././a",       "../a"          },
    {"./../../",       "../.."         },
    {"./../../.",      "../.."         },
    {"./../../..",     "../../.."      },
    {"./../../a",      "../../a"       },
    {"./../a/",        "../a"          },
    {"./../a/.",       "../a"          },
    {"./../a/..",      ".."            },
    {"./../a/b",       "../a/b"        },
    {"./a//",          "a"             },
    {"./a//.",         "a"             },
    {"./a//..",        "."             },
    {"./a//b",         "a/b"           },
    {"./a/./",         "a"             },
    {"./a/./.",        "a"             },
    {"./a/./..",       "."             },
    {"./a/./b",        "a/b"           },
    {"./a/../",        "."             },
    {"./a/../.",       "."             },
    {"./a/../..",      ".."            },
    {"./a/../b",       "b"             },
    {"./a/b/",         "a/b"           },
    {"./a/b/.",        "a/b"           },
    {"./a/b/..",       "a"             },
    {"./a/b/c",        "a/b/c"         },
    {"..///",          ".."            },
    {"..///.",         ".."            },
    {"..///..",        "../.."         },
    {"..///a",         "../a"          },
    {"..//./",         ".."            },
    {"..//./.",        ".."            },
    {"..//./..",       "../.."         },
    {"..//./a",        "../a"          },
    {"..//../",        "../.."         },
    {"..//../.",       "../.."         },
    {"..//../..",      "../../.."      },
    {"..//../a",       "../../a"       },
    {"..//a/",         "../a"          },
    {"..//a/.",        "../a"          },
    {"..//a/..",       ".."            },
    {"..//a/b",        "../a/b"        },
    {".././/",         ".."            },
    {".././/.",        ".."            },
    {".././/..",       "../.."         },
    {".././/a",        "../a"          },
    {"../././",        ".."            },
    {"../././.",       ".."            },
    {"../././..",      "../.."         },
    {"../././a",       "../a"          },
    {".././../",       "../.."         },
    {".././../.",      "../.."         },
    {".././../..",     "../../.."      },
    {".././../a",      "../../a"       },
    {".././a/",        "../a"          },
    {".././a/.",       "../a"          },
    {".././a/..",      ".."            },
    {".././a/b",       "../a/b"        },
    {"../..//",        "../.."         },
    {"../..//.",       "../.."         },
    {"../..//..",      "../../.."      },
    {"../..//a",       "../../a"       },
    {"../.././",       "../.."         },
    {"../.././.",      "../.."         },
    {"../.././..",     "../../.."      },
    {"../.././a",      "../../a"       },
    {"../../../",      "../../.."      },
    {"../../../.",     "../../.."      },
    {"../../../..",    "../../../.."   },
    {"../../../a",     "../../../a"    },
    {"../../a/",       "../../a"       },
    {"../../a/.",      "../../a"       },
    {"../../a/..",     "../.."         },
    {"../../a/b",      "../../a/b"     },
    {"../a//",         "../a"          },
    {"../a//.",        "../a"          },
    {"../a//..",       ".."            },
    {"../a//b",        "../a/b"        },
    {"../a/./",        "../a"          },
    {"../a/./.",       "../a"          },
    {"../a/./..",      ".."            },
    {"../a/./b",       "../a/b"        },
    {"../a/../",       ".."            },
    {"../a/../.",      ".."            },
    {"../a/../..",     "../.."         },
    {"../a/../b",      "../b"          },
    {"../a/b/",        "../a/b"        },
    {"../a/b/.",       "../a/b"        },
    {"../a/b/..",      "../a"          },
    {"../a/b/c",       "../a/b/c"      },
    {"a///",           "a"             },
    {"a///.",          "a"             },
    {"a///..",         "."             },
    {"a///b",          "a/b"           },
    {"a//./",          "a"             },
    {"a//./.",         "a"             },
    {"a//./..",        "."             },
    {"a//./b",         "a/b"           },
    {"a//../",         "."             },
    {"a//../.",        "."             },
    {"a//../..",       ".."            },
    {"a//../b",        "b"             },
    {"a//b/",          "a/b"           },
    {"a//b/.",         "a/b"           },
    {"a//b/..",        "a"             },
    {"a//b/c",         "a/b/c"         },
    {"a/.//",          "a"             },
    {"a/.//.",         "a"             },
    {"a/.//..",        "."             },
    {"a/.//b",         "a/b"           },
    {"a/././",         "a"             },
    {"a/././.",        "a"             },
    {"a/././..",       "."             },
    {"a/././b",        "a/b"           },
    {"a/./../",        "."             },
    {"a/./../.",       "."             },
    {"a/./../..",      ".."            },
    {"a/./../b",       "b"             },
    {"a/./b/",         "a/b"           },
    {"a/./b/.",        "a/b"           },
    {"a/./b/..",       "a"             },
    {"a/./b/c",        "a/b/c"         },
    {"a/..//",         "."             },
    {"a/..//.",        "."             },
    {"a/..//..",       ".."            },
    {"a/..//b",        "b"             },
    {"a/.././",        "."             },
    {"a/.././.",       "."             },
    {"a/.././..",      ".."            },
    {"a/.././b",       "b"             },
    {"a/../../",       ".."            },
    {"a/../../.",      ".."            },
    {"a/../../..",     "../.."         },
    {"a/../../b",      "../b"          },
    {"a/../b/",        "b"             },
    {"a/../b/.",       "b"             },
    {"a/../b/..",      "."             },
    {"a/../b/c",       "b/c"           },
    {"a/b//",          "a/b"           },
    {"a/b//.",         "a/b"           },
    {"a/b//..",        "a"             },
    {"a/b//c",         "a/b/c"         },
    {"a/b/./",         "a/b"           },
    {"a/b/./.",        "a/b"           },
    {"a/b/./..",       "a"             },
    {"a/b/./c",        "a/b/c"         },
    {"a/b/../",        "a"             },
    {"a/b/../.",       "a"             },
    {"a/b/../..",      "."             },
    {"a/b/../c",       "a/c"           },
    {"a/b/c/",         "a/b/c"         },
    {"a/b/c/.",        "a/b/c"         },
    {"a/b/c/..",       "a/b"           },
    {"a/b/c/d",        "a/b/c/d"       },
};

const std::vector<NormpathTestCase> windows_cases = {
    {"C:/a/b",              "C:/a/b" },
    {"C:/a/b/..",           "C:/a"   },
    {"C:/a/b/../..",        "C:"     },
    {"C:/a/b/../../..",     "C:"     },
    {"//a/b/c",             "//a/b/c"},
    {"//a/b/c/..",          "//a/b"  },
    {"//a/b/c/../..",       "//a/b"  },
    {"//a/b/c/../../..",    "//a/b"  },
    {"//a/b/c/../../../..", "//a/b"  },
};

const std::vector<NormpathTestCase> posix_cases = {
    {"C:/a/b",              "C:/a/b" },
    {"C:/a/b/..",           "C:/a"   },
    {"C:/a/b/../..",        "C:"     },
    {"C:/a/b/../../..",     "."      },
    {"//a/b/c",             "//a/b/c"},
    {"//a/b/c/..",          "//a/b"  },
    {"//a/b/c/../..",       "//a"    },
    {"//a/b/c/../../..",    "//"     },
    {"//a/b/c/../../../..", "//"     },
    {"///a/b/c",            "/a/b/c" },
    {"///a/b/c/..",         "/a/b"   },
    {"///a/b/c/../..",      "/a"     },
    {"///a/b/c/../../..",   "/"      },
};

const std::vector<NormpathTestCase> platform_cases = platform::os == platform::Windows ? windows_cases : posix_cases;

#endif
