import os
import re
import psutil
from SCons.Environment import Environment
from SCons.Script import AddOption
from walkmate import get_child_files as tree

libs = [
    "gtest",
    "pthread",
]

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

env = Environment(
    LIBS=libs,
    ENV={"PATH": os.getenv("PATH", [])},
    CXXFLAGS=["-std=c++17"],
    CPPPATH=os.getenv("CPPPATH", "/usr/include").split(","),
    LIBPATH=os.getenv("LIBPATH", "/usr/lib").split(","),
    # CXXCOMSTR="Compiling $TARGET",
    # LINKCOMSTR="Linking $TARGET",
    num_jobs=psutil.cpu_count(),
)

AddOption("--iwyu", action="store_true")
AddOption("--typecheck", action="store_true")

if env["PLATFORM"] == "win32":
    env["CXX"] = "g++"
    env["LIBS"].remove("pthread")
    env["tools"] = ["mingw"]

elif GetOption("typecheck"):
    env["LINK"] = ":"
    env["CXXFLAGS"].extend(["-S", "-O0"])

elif GetOption("iwyu"):
    env["CXX"] = "include-what-you-use"

else:
    env["CXX"] = "clang++"
    env["CXXFLAGS"].extend(warnings)

env.Program(
    target="dist/tests",
    source=[i for i in tree(".") if re.search("\.cpp$", i)],
)
