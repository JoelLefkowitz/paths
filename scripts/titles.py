import os


def docstring(filename):
    return "\n".join(
        [
            f"// ʕ •ᴥ•ʔ Paths - {filename} ʕ•ᴥ• ʔ",
            "// Cross platform OS path operations and executable path retrieval.",
            "// https://github.com/joellefkowitz/paths",
            "// Version: 0.1.0",
            "// License: MIT",
        ]
    )


def guard(filename):
    upper = filename.upper()
    return "\n".join(
        [
            f"#ifndef LIB_PATHS_{upper}_H",
            f"#define LIB_PATHS_{upper}_H",
        ]
    )


src = os.path.normpath(os.path.join(__file__, "..", "..", "src"))

if __name__ == "__main__":
    for filename in os.listdir(src):
        filepath = os.path.join(src, filename)
        title = docstring(filename)

        if filename == "detect.hpp":
            continue

        if filename.endswith(".hpp"):
            title += "\n" * 2 + guard(filename[:-4])

        elif filename.endswith(".cpp"):
            title += "\n" * 2 + f'#include "{filename[:-4]}.hpp"'

        else:
            continue

        with open(filepath, "r") as stream:
            assert stream.read().startswith(title)
            print(f"✓ {filepath}")
