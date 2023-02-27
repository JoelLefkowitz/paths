import platform
from functools import reduce
from glob import glob

import psutil
from emoji import emojize
from SCons.Environment import Environment


def prefix(arr, x):
    return [f"{x}{i}" for i in arr]


def globs(patterns):
    return reduce(lambda acc, x: acc | set(glob(x, recursive=True)), patterns, set())


def find(include, exclude):
    return list(globs(include) - globs(exclude))


compiler = "g++" if platform.system() == "Windows" else "clang++"

flags = [
    "-g",
    "-std=c++11",
]

libs = [
    "gtest"
]

warnings = [
    "all",
    "conversion",
    "extra-semi",
    "extra",
    "error",
    "missing-declarations",
    "pedantic",
    "shadow-uncaptured-local",
    "shadow",
]

ignore = [
    "vla-extension",
    "unused-parameter",
]

env = Environment(
    CXX=compiler,
    LIBS=libs,
    CPPFLAGS=" ".join(prefix(warnings, "-W") + prefix(ignore, "-Wno-")),
    CXXFLAGS=" ".join(flags),
    CXXCOMSTR=emojize(":wrench: Compiling $TARGET"),
    LINKCOMSTR=emojize(":link: Linking $TARGET"),
)

env.SetOption("num_jobs", psutil.cpu_count())

test = env.Program(
    target="dist/test",
    source=find(["src/**/*.cpp", "tests/**/*.cpp"], []),
)

env.Alias("test", "dist/test")
env.Default(test)
