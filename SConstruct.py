import re
import os
import psutil
from walkmate import get_child_files
from emoji import emojize
from SCons.Environment import Environment
from SCons.Script import AddOption

env = Environment(
    LIBS=["gtest", "pthread"],
    CXXFLAGS=["-std=c++17"],
    CPPPATH=os.getenv("CPPPATH", "/usr/include"),
    LIBPATH=os.getenv("LIBPATH", "/usr/lib"),
    CXXCOMSTR="Compiling $TARGET",
    LINKCOMSTR="Linking $TARGET",
    num_jobs=psutil.cpu_count(),
)

warnings = [
    "-Wall",
    "-Wconversion",
    "-Wextra",
    "-Wmissing-declarations",
    "-Wpedantic",
    "-Wshadow-uncaptured-local",
    "-Wshadow",
    "-Wno-deprecated-declarations",
    "-Wno-macro-redefined",
    "-Wno-missing-braces",
    "-Wno-unknown-warning-option",
    "-Wno-unused-parameter",
    "-Wno-vla-extension",
    "-Wno-everything",
]

AddOption("--iwyu", action="store_true")
AddOption("--typecheck", action="store_true")

if env["PLATFORM"] == "darwin":
    env["CXX"] = "clang++"
    env["CXXFLAGS"].extend(warnings)

if GetOption("iwyu"):
    env["CXX"] = "include-what-you-use"

if GetOption("typecheck"):
    env["LINK"] = ":"
    env["CXXFLAGS"].extend(["-S", "-O0"])

sources = lambda x: [i for i in get_child_files(".") if re.search(x, i)]

env.Program(target="dist/tests", source=sources("\.cpp$"))
