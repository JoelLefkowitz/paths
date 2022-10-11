#include "../../src/normalise.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(normalise, normalise) {
    struct TestCase {
        std::vector<std::string> paths;
        std::vector<std::string> expected;
    };

    std::vector<TestCase> cases = {
        {{""},               {"."}             },
        {{"."},              {"."}             },
        {{".."},             {".."}            },
        {{"a"},              {"a"}             },
        {{"", ""},           {"", ""}          },
        {{"", "."},          {"", ""}          },
        {{"", ".."},         {"", ""}          },
        {{"", "a"},          {"", "a"}         },
        {{".", ""},          {"."}             },
        {{".", "."},         {"."}             },
        {{".", ".."},        {".."}            },
        {{".", "a"},         {"a"}             },
        {{"..", ""},         {".."}            },
        {{"..", "."},        {".."}            },
        {{"..", ".."},       {"..", ".."}      },
        {{"..", "a"},        {"..", "a"}       },
        {{"a", ""},          {"a"}             },
        {{"a", "."},         {"a"}             },
        {{"a", ".."},        {"."}             },
        {{"a", "b"},         {"a", "b"}        },
        {{"", "", ""},       {"", "", ""}      },
        {{"", "", "."},      {"", "", ""}      },
        {{"", "", ".."},     {"", "", ""}      },
        {{"", "", "a"},      {"", "", "a"}     },
        {{"", ".", ""},      {"", ""}          },
        {{"", ".", "."},     {"", ""}          },
        {{"", ".", ".."},    {"", ""}          },
        {{"", ".", "a"},     {"", "a"}         },
        {{"", "..", ""},     {"", ""}          },
        {{"", "..", "."},    {"", ""}          },
        {{"", "..", ".."},   {"", ""}          },
        {{"", "..", "a"},    {"", "a"}         },
        {{"", "a", ""},      {"", "a"}         },
        {{"", "a", "."},     {"", "a"}         },
        {{"", "a", ".."},    {"", ""}          },
        {{"", "a", "b"},     {"", "a", "b"}    },
        {{".", "", ""},      {"."}             },
        {{".", "", "."},     {"."}             },
        {{".", "", ".."},    {".."}            },
        {{".", "", "a"},     {"a"}             },
        {{".", ".", ""},     {"."}             },
        {{".", ".", "."},    {"."}             },
        {{".", ".", ".."},   {".."}            },
        {{".", ".", "a"},    {"a"}             },
        {{".", "..", ""},    {".."}            },
        {{".", "..", "."},   {".."}            },
        {{".", "..", ".."},  {"..", ".."}      },
        {{".", "..", "a"},   {"..", "a"}       },
        {{".", "a", ""},     {"a"}             },
        {{".", "a", "."},    {"a"}             },
        {{".", "a", ".."},   {"."}             },
        {{".", "a", "b"},    {"a", "b"}        },
        {{"..", "", ""},     {".."}            },
        {{"..", "", "."},    {".."}            },
        {{"..", "", ".."},   {"..", ".."}      },
        {{"..", "", "a"},    {"..", "a"}       },
        {{"..", ".", ""},    {".."}            },
        {{"..", ".", "."},   {".."}            },
        {{"..", ".", ".."},  {"..", ".."}      },
        {{"..", ".", "a"},   {"..", "a"}       },
        {{"..", "..", ""},   {"..", ".."}      },
        {{"..", "..", "."},  {"..", ".."}      },
        {{"..", "..", ".."}, {"..", "..", ".."}},
        {{"..", "..", "a"},  {"..", "..", "a"} },
        {{"..", "a", ""},    {"..", "a"}       },
        {{"..", "a", "."},   {"..", "a"}       },
        {{"..", "a", ".."},  {".."}            },
        {{"..", "a", "b"},   {"..", "a", "b"}  },
        {{"a", "", ""},      {"a"}             },
        {{"a", "", "."},     {"a"}             },
        {{"a", "", ".."},    {"."}             },
        {{"a", "", "b"},     {"a", "b"}        },
        {{"a", ".", ""},     {"a"}             },
        {{"a", ".", "."},    {"a"}             },
        {{"a", ".", ".."},   {"."}             },
        {{"a", ".", "b"},    {"a", "b"}        },
        {{"a", "..", ""},    {"."}             },
        {{"a", "..", "."},   {"."}             },
        {{"a", "..", ".."},  {".."}            },
        {{"a", "..", "b"},   {"b"}             },
        {{"a", "b", ""},     {"a", "b"}        },
        {{"a", "b", "."},    {"a", "b"}        },
        {{"a", "b", ".."},   {"a"}             },
        {{"a", "b", "c"},    {"a", "b", "c"}   },
    };

    for (auto test : cases) {
        EXPECT_EQ(paths::normalise(test.paths), test.expected);
    }
};
