import inspect
import os
from conanfile import Recipe
from miniscons import (
    Build,
    Flag,
    Routine,
    Script,
    Target,
    Tasks,
    conan,
    packages,
    flags,
)
from walkmate import tree

env = conan()

runtime = Build(
    "runtime",
    tree("src", r"(?<!\.spec)\.cpp$", ["test.cpp"]),
    flags("c++17"),
    shared=True,
    rename=Recipe.name,
)

tests = Build(
    "tests",
    [
        *tree("src", r"\.cpp$"),
        *tree("test", r"\.cpp$"),
    ],
    flags("c++17"),
    packages(["gtest"]),
)

test = Target(
    "test",
    tests,
    ["--gtest_brief"],
)

includes = tests.packages["CPPPATH"]

cspell = Script(
    "cspell",
    ["npx", "cspell", ".", "--dot", "--gitignore"],
)

cppclean = Script(
    "cppclean",
    ["cppclean", "."],
)

cppcheck = Script(
    "cppcheck",
    [
        "cppcheck",
        tree("src", r"\.(cpp)$"),
        [f"-I{i}" for i in includes],
        "--quiet",
        "--enable=all",
        "--suppressions-list=.cppcheck",
        "--inline-suppr",
        [f"--suppress=*:{i}/*" for i in includes],
    ],
)

clang_tidy = Script(
    "clang-tidy",
    ["clang-tidy", tree("src", r"\.(cpp)$"), "--", [f"-I{i}" for i in includes]],
)

trufflehog = Script(
    "trufflehog",
    ["trufflehog3"],
)

clang_format = Script(
    "clang-format",
    ["clang-format", "-i", tree(".", r"\.(cpp|hpp|tpp)$")],
)

prettier = Script(
    "prettier",
    ["npx", "prettier", ".", "--write"],
)

doxygen = Script(
    "doxygen",
    ["doxygen", "docs/doxygen/Doxyfile"],
)

breathe = Script(
    "breathe",
    [
        "breathe-apidoc",
        "./docs/doxygen/dist",
        "--output-dir",
        "docs/sphinx/dist",
        "--members",
    ],
)

sphinx = Script(
    "sphinx-build",
    ["sphinx-build", "docs/sphinx", "docs/dist"],
)

lint = Routine(
    "lint",
    [cspell, cppclean, cppcheck, clang_tidy, trufflehog],
)

fmt = Routine(
    "format",
    [clang_format, prettier],
)

docs = Routine(
    "docs",
    [doxygen, breathe, sphinx],
)

cli = Tasks(
    [runtime, tests],
    [test],
    [*lint.scripts, *fmt.scripts, *docs.scripts],
    [lint, fmt, docs],
)

cwd = os.path.dirname(inspect.getfile(lambda: None))

env["ENV"].update(
    {
        "DIRNAME": "dist",
        "FILENAME": "tests",
        "DIRPATH": os.path.join(cwd, "dist"),
        "ABSPATH": os.path.join(cwd, "dist/a/b/c"),
        "FILEPATH": os.path.join(cwd, "dist/tests"),
    }
)

cli.register(env)
