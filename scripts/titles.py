import os


def docstring(name):
    return "\n".join(
        [
            f"// ʕ •ᴥ•ʔ Paths - {name} ʕ•ᴥ• ʔ",
            "// OS specific path operations and executable path retrieval.",
            "// https://github.com/joellefkowitz/paths",
            "// Version: 0.1.0",
            "// License: MIT",
        ]
    )


def guard(name):
    upper = name.upper()
    return "\n".join(
        [
            f"#ifndef LIB_PATHS_{upper}_H",
            f"#define LIB_PATHS_{upper}_H",
        ]
    )


src = os.path.normpath(os.path.join(__file__, "..", "..", "src"))

for name in os.listdir(src):
    path = os.path.join(src, name)
    title = docstring(name)

    if name == "detect.hpp":
        continue

    if name.endswith(".hpp"):
        title += "\n" * 2 + guard(name[:-4])

    if name.endswith(".cpp"):
        title += "\n" * 2 + f'#include "{name[:-4]}.hpp"'

    with open(path, "r") as stream:
        print(name)
        assert stream.read().startswith(title)
