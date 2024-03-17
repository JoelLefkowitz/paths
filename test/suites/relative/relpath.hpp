#ifndef TEST_PATHS_RELPATH_H
#define TEST_PATHS_RELPATH_H

#include <string>
#include <vector>

struct RelpathTestCase {
    std::string source;
    std::string target;
    std::string expected;
};

const std::vector<RelpathTestCase> cases = {
    {".",     ".",     "."             },
    {".",     "..",    ".."            },
    {".",     "a",     "a"             },
    {".",     "./",    "."             },
    {".",     "./.",   "."             },
    {".",     "./..",  ".."            },
    {".",     "./a",   "a"             },
    {".",     "../",   ".."            },
    {".",     "../.",  ".."            },
    {".",     "../..", "../.."         },
    {".",     "../a",  "../a"          },
    {".",     "a/",    "a"             },
    {".",     "a/.",   "a"             },
    {".",     "a/..",  "."             },
    {".",     "a/b",   "a/b"           },
    {"a",     ".",     ".."            },
    {"a",     "..",    "../.."         },
    {"a",     "a",     "."             },
    {"a",     "./",    ".."            },
    {"a",     "./.",   ".."            },
    {"a",     "./..",  "../.."         },
    {"a",     "./a",   "."             },
    {"a",     "../",   "../.."         },
    {"a",     "../.",  "../.."         },
    {"a",     "../..", "../../.."      },
    {"a",     "../a",  "../../a"       },
    {"a",     "a/",    "."             },
    {"a",     "a/.",   "."             },
    {"a",     "a/..",  ".."            },
    {"a",     "a/b",   "b"             },
    {"./",    ".",     "."             },
    {"./",    "..",    ".."            },
    {"./",    "a",     "a"             },
    {"./",    "./",    "."             },
    {"./",    "./.",   "."             },
    {"./",    "./..",  ".."            },
    {"./",    "./a",   "a"             },
    {"./",    "../",   ".."            },
    {"./",    "../.",  ".."            },
    {"./",    "../..", "../.."         },
    {"./",    "../a",  "../a"          },
    {"./",    "a/",    "a"             },
    {"./",    "a/.",   "a"             },
    {"./",    "a/..",  "."             },
    {"./",    "a/b",   "a/b"           },
    {"./.",   ".",     "."             },
    {"./.",   "..",    ".."            },
    {"./.",   "a",     "a"             },
    {"./.",   "./",    "."             },
    {"./.",   "./.",   "."             },
    {"./.",   "./..",  ".."            },
    {"./.",   "./a",   "a"             },
    {"./.",   "../",   ".."            },
    {"./.",   "../.",  ".."            },
    {"./.",   "../..", "../.."         },
    {"./.",   "../a",  "../a"          },
    {"./.",   "a/",    "a"             },
    {"./.",   "a/.",   "a"             },
    {"./.",   "a/..",  "."             },
    {"./.",   "a/b",   "a/b"           },
    {"./a",   ".",     ".."            },
    {"./a",   "..",    "../.."         },
    {"./a",   "a",     "."             },
    {"./a",   "./",    ".."            },
    {"./a",   "./.",   ".."            },
    {"./a",   "./..",  "../.."         },
    {"./a",   "./a",   "."             },
    {"./a",   "../",   "../.."         },
    {"./a",   "../.",  "../.."         },
    {"./a",   "../..", "../../.."      },
    {"./a",   "../a",  "../../a"       },
    {"./a",   "a/",    "."             },
    {"./a",   "a/.",   "."             },
    {"./a",   "a/..",  ".."            },
    {"./a",   "a/b",   "b"             },
    {"a/",    ".",     ".."            },
    {"a/",    "..",    "../.."         },
    {"a/",    "a",     "."             },
    {"a/",    "./",    ".."            },
    {"a/",    "./.",   ".."            },
    {"a/",    "./..",  "../.."         },
    {"a/",    "./a",   "."             },
    {"a/",    "../",   "../.."         },
    {"a/",    "../.",  "../.."         },
    {"a/",    "../..", "../../.."      },
    {"a/",    "../a",  "../../a"       },
    {"a/",    "a/",    "."             },
    {"a/",    "a/.",   "."             },
    {"a/",    "a/..",  ".."            },
    {"a/",    "a/b",   "b"             },
    {"a/.",   ".",     ".."            },
    {"a/.",   "..",    "../.."         },
    {"a/.",   "a",     "."             },
    {"a/.",   "./",    ".."            },
    {"a/.",   "./.",   ".."            },
    {"a/.",   "./..",  "../.."         },
    {"a/.",   "./a",   "."             },
    {"a/.",   "../",   "../.."         },
    {"a/.",   "../.",  "../.."         },
    {"a/.",   "../..", "../../.."      },
    {"a/.",   "../a",  "../../a"       },
    {"a/.",   "a/",    "."             },
    {"a/.",   "a/.",   "."             },
    {"a/.",   "a/..",  ".."            },
    {"a/.",   "a/b",   "b"             },
    {"a/b",   ".",     "../.."         },
    {"a/b",   "..",    "../../.."      },
    {"a/b",   "a",     ".."            },
    {"a/b",   "./",    "../.."         },
    {"a/b",   "./.",   "../.."         },
    {"a/b",   "./..",  "../../.."      },
    {"a/b",   "./a",   ".."            },
    {"a/b",   "../",   "../../.."      },
    {"a/b",   "../.",  "../../.."      },
    {"a/b",   "../..", "../../../.."   },
    {"a/b",   "../a",  "../../../a"    },
    {"a/b",   "a/",    ".."            },
    {"a/b",   "a/.",   ".."            },
    {"a/b",   "a/..",  "../.."         },
    {"a/b",   "a/b",   "."             },
    {".//",   ".",     "."             },
    {".//",   "..",    ".."            },
    {".//",   "a",     "a"             },
    {".//",   "./",    "."             },
    {".//",   "./.",   "."             },
    {".//",   "./..",  ".."            },
    {".//",   "./a",   "a"             },
    {".//",   "../",   ".."            },
    {".//",   "../.",  ".."            },
    {".//",   "../..", "../.."         },
    {".//",   "../a",  "../a"          },
    {".//",   "a/",    "a"             },
    {".//",   "a/.",   "a"             },
    {".//",   "a/..",  "."             },
    {".//",   "a/b",   "a/b"           },
    {".//.",  ".",     "."             },
    {".//.",  "..",    ".."            },
    {".//.",  "a",     "a"             },
    {".//.",  "./",    "."             },
    {".//.",  "./.",   "."             },
    {".//.",  "./..",  ".."            },
    {".//.",  "./a",   "a"             },
    {".//.",  "../",   ".."            },
    {".//.",  "../.",  ".."            },
    {".//.",  "../..", "../.."         },
    {".//.",  "../a",  "../a"          },
    {".//.",  "a/",    "a"             },
    {".//.",  "a/.",   "a"             },
    {".//.",  "a/..",  "."             },
    {".//.",  "a/b",   "a/b"           },
    {".//a",  ".",     ".."            },
    {".//a",  "..",    "../.."         },
    {".//a",  "a",     "."             },
    {".//a",  "./",    ".."            },
    {".//a",  "./.",   ".."            },
    {".//a",  "./..",  "../.."         },
    {".//a",  "./a",   "."             },
    {".//a",  "../",   "../.."         },
    {".//a",  "../.",  "../.."         },
    {".//a",  "../..", "../../.."      },
    {".//a",  "../a",  "../../a"       },
    {".//a",  "a/",    "."             },
    {".//a",  "a/.",   "."             },
    {".//a",  "a/..",  ".."            },
    {".//a",  "a/b",   "b"             },
    {"././",  ".",     "."             },
    {"././",  "..",    ".."            },
    {"././",  "a",     "a"             },
    {"././",  "./",    "."             },
    {"././",  "./.",   "."             },
    {"././",  "./..",  ".."            },
    {"././",  "./a",   "a"             },
    {"././",  "../",   ".."            },
    {"././",  "../.",  ".."            },
    {"././",  "../..", "../.."         },
    {"././",  "../a",  "../a"          },
    {"././",  "a/",    "a"             },
    {"././",  "a/.",   "a"             },
    {"././",  "a/..",  "."             },
    {"././",  "a/b",   "a/b"           },
    {"././.", ".",     "."             },
    {"././.", "..",    ".."            },
    {"././.", "a",     "a"             },
    {"././.", "./",    "."             },
    {"././.", "./.",   "."             },
    {"././.", "./..",  ".."            },
    {"././.", "./a",   "a"             },
    {"././.", "../",   ".."            },
    {"././.", "../.",  ".."            },
    {"././.", "../..", "../.."         },
    {"././.", "../a",  "../a"          },
    {"././.", "a/",    "a"             },
    {"././.", "a/.",   "a"             },
    {"././.", "a/..",  "."             },
    {"././.", "a/b",   "a/b"           },
    {"././a", ".",     ".."            },
    {"././a", "..",    "../.."         },
    {"././a", "a",     "."             },
    {"././a", "./",    ".."            },
    {"././a", "./.",   ".."            },
    {"././a", "./..",  "../.."         },
    {"././a", "./a",   "."             },
    {"././a", "../",   "../.."         },
    {"././a", "../.",  "../.."         },
    {"././a", "../..", "../../.."      },
    {"././a", "../a",  "../../a"       },
    {"././a", "a/",    "."             },
    {"././a", "a/.",   "."             },
    {"././a", "a/..",  ".."            },
    {"././a", "a/b",   "b"             },
    {"./a/",  ".",     ".."            },
    {"./a/",  "..",    "../.."         },
    {"./a/",  "a",     "."             },
    {"./a/",  "./",    ".."            },
    {"./a/",  "./.",   ".."            },
    {"./a/",  "./..",  "../.."         },
    {"./a/",  "./a",   "."             },
    {"./a/",  "../",   "../.."         },
    {"./a/",  "../.",  "../.."         },
    {"./a/",  "../..", "../../.."      },
    {"./a/",  "../a",  "../../a"       },
    {"./a/",  "a/",    "."             },
    {"./a/",  "a/.",   "."             },
    {"./a/",  "a/..",  ".."            },
    {"./a/",  "a/b",   "b"             },
    {"./a/.", ".",     ".."            },
    {"./a/.", "..",    "../.."         },
    {"./a/.", "a",     "."             },
    {"./a/.", "./",    ".."            },
    {"./a/.", "./.",   ".."            },
    {"./a/.", "./..",  "../.."         },
    {"./a/.", "./a",   "."             },
    {"./a/.", "../",   "../.."         },
    {"./a/.", "../.",  "../.."         },
    {"./a/.", "../..", "../../.."      },
    {"./a/.", "../a",  "../../a"       },
    {"./a/.", "a/",    "."             },
    {"./a/.", "a/.",   "."             },
    {"./a/.", "a/..",  ".."            },
    {"./a/.", "a/b",   "b"             },
    {"./a/b", ".",     "../.."         },
    {"./a/b", "..",    "../../.."      },
    {"./a/b", "a",     ".."            },
    {"./a/b", "./",    "../.."         },
    {"./a/b", "./.",   "../.."         },
    {"./a/b", "./..",  "../../.."      },
    {"./a/b", "./a",   ".."            },
    {"./a/b", "../",   "../../.."      },
    {"./a/b", "../.",  "../../.."      },
    {"./a/b", "../..", "../../../.."   },
    {"./a/b", "../a",  "../../../a"    },
    {"./a/b", "a/",    ".."            },
    {"./a/b", "a/.",   ".."            },
    {"./a/b", "a/..",  "../.."         },
    {"./a/b", "a/b",   "."             },
    {"a//",   ".",     ".."            },
    {"a//",   "..",    "../.."         },
    {"a//",   "a",     "."             },
    {"a//",   "./",    ".."            },
    {"a//",   "./.",   ".."            },
    {"a//",   "./..",  "../.."         },
    {"a//",   "./a",   "."             },
    {"a//",   "../",   "../.."         },
    {"a//",   "../.",  "../.."         },
    {"a//",   "../..", "../../.."      },
    {"a//",   "../a",  "../../a"       },
    {"a//",   "a/",    "."             },
    {"a//",   "a/.",   "."             },
    {"a//",   "a/..",  ".."            },
    {"a//",   "a/b",   "b"             },
    {"a//.",  ".",     ".."            },
    {"a//.",  "..",    "../.."         },
    {"a//.",  "a",     "."             },
    {"a//.",  "./",    ".."            },
    {"a//.",  "./.",   ".."            },
    {"a//.",  "./..",  "../.."         },
    {"a//.",  "./a",   "."             },
    {"a//.",  "../",   "../.."         },
    {"a//.",  "../.",  "../.."         },
    {"a//.",  "../..", "../../.."      },
    {"a//.",  "../a",  "../../a"       },
    {"a//.",  "a/",    "."             },
    {"a//.",  "a/.",   "."             },
    {"a//.",  "a/..",  ".."            },
    {"a//.",  "a/b",   "b"             },
    {"a//b",  ".",     "../.."         },
    {"a//b",  "..",    "../../.."      },
    {"a//b",  "a",     ".."            },
    {"a//b",  "./",    "../.."         },
    {"a//b",  "./.",   "../.."         },
    {"a//b",  "./..",  "../../.."      },
    {"a//b",  "./a",   ".."            },
    {"a//b",  "../",   "../../.."      },
    {"a//b",  "../.",  "../../.."      },
    {"a//b",  "../..", "../../../.."   },
    {"a//b",  "../a",  "../../../a"    },
    {"a//b",  "a/",    ".."            },
    {"a//b",  "a/.",   ".."            },
    {"a//b",  "a/..",  "../.."         },
    {"a//b",  "a/b",   "."             },
    {"a/./",  ".",     ".."            },
    {"a/./",  "..",    "../.."         },
    {"a/./",  "a",     "."             },
    {"a/./",  "./",    ".."            },
    {"a/./",  "./.",   ".."            },
    {"a/./",  "./..",  "../.."         },
    {"a/./",  "./a",   "."             },
    {"a/./",  "../",   "../.."         },
    {"a/./",  "../.",  "../.."         },
    {"a/./",  "../..", "../../.."      },
    {"a/./",  "../a",  "../../a"       },
    {"a/./",  "a/",    "."             },
    {"a/./",  "a/.",   "."             },
    {"a/./",  "a/..",  ".."            },
    {"a/./",  "a/b",   "b"             },
    {"a/./.", ".",     ".."            },
    {"a/./.", "..",    "../.."         },
    {"a/./.", "a",     "."             },
    {"a/./.", "./",    ".."            },
    {"a/./.", "./.",   ".."            },
    {"a/./.", "./..",  "../.."         },
    {"a/./.", "./a",   "."             },
    {"a/./.", "../",   "../.."         },
    {"a/./.", "../.",  "../.."         },
    {"a/./.", "../..", "../../.."      },
    {"a/./.", "../a",  "../../a"       },
    {"a/./.", "a/",    "."             },
    {"a/./.", "a/.",   "."             },
    {"a/./.", "a/..",  ".."            },
    {"a/./.", "a/b",   "b"             },
    {"a/./b", ".",     "../.."         },
    {"a/./b", "..",    "../../.."      },
    {"a/./b", "a",     ".."            },
    {"a/./b", "./",    "../.."         },
    {"a/./b", "./.",   "../.."         },
    {"a/./b", "./..",  "../../.."      },
    {"a/./b", "./a",   ".."            },
    {"a/./b", "../",   "../../.."      },
    {"a/./b", "../.",  "../../.."      },
    {"a/./b", "../..", "../../../.."   },
    {"a/./b", "../a",  "../../../a"    },
    {"a/./b", "a/",    ".."            },
    {"a/./b", "a/.",   ".."            },
    {"a/./b", "a/..",  "../.."         },
    {"a/./b", "a/b",   "."             },
    {"a/b/",  ".",     "../.."         },
    {"a/b/",  "..",    "../../.."      },
    {"a/b/",  "a",     ".."            },
    {"a/b/",  "./",    "../.."         },
    {"a/b/",  "./.",   "../.."         },
    {"a/b/",  "./..",  "../../.."      },
    {"a/b/",  "./a",   ".."            },
    {"a/b/",  "../",   "../../.."      },
    {"a/b/",  "../.",  "../../.."      },
    {"a/b/",  "../..", "../../../.."   },
    {"a/b/",  "../a",  "../../../a"    },
    {"a/b/",  "a/",    ".."            },
    {"a/b/",  "a/.",   ".."            },
    {"a/b/",  "a/..",  "../.."         },
    {"a/b/",  "a/b",   "."             },
    {"a/b/.", ".",     "../.."         },
    {"a/b/.", "..",    "../../.."      },
    {"a/b/.", "a",     ".."            },
    {"a/b/.", "./",    "../.."         },
    {"a/b/.", "./.",   "../.."         },
    {"a/b/.", "./..",  "../../.."      },
    {"a/b/.", "./a",   ".."            },
    {"a/b/.", "../",   "../../.."      },
    {"a/b/.", "../.",  "../../.."      },
    {"a/b/.", "../..", "../../../.."   },
    {"a/b/.", "../a",  "../../../a"    },
    {"a/b/.", "a/",    ".."            },
    {"a/b/.", "a/.",   ".."            },
    {"a/b/.", "a/..",  "../.."         },
    {"a/b/.", "a/b",   "."             },
    {"a/b/c", ".",     "../../.."      },
    {"a/b/c", "..",    "../../../.."   },
    {"a/b/c", "a",     "../.."         },
    {"a/b/c", "./",    "../../.."      },
    {"a/b/c", "./.",   "../../.."      },
    {"a/b/c", "./..",  "../../../.."   },
    {"a/b/c", "./a",   "../.."         },
    {"a/b/c", "../",   "../../../.."   },
    {"a/b/c", "../.",  "../../../.."   },
    {"a/b/c", "../..", "../../../../.."},
    {"a/b/c", "../a",  "../../../../a" },
    {"a/b/c", "a/",    "../.."         },
    {"a/b/c", "a/.",   "../.."         },
    {"a/b/c", "a/..",  "../../.."      },
    {"a/b/c", "a/b",   ".."            },
};

#endif
