from conan import ConanFile
from conan.tools.files import copy
from conan.tools.scons import SConsDeps


class Recipe(ConanFile):
    name = "paths"
    version = "0.0.0"

    requires = [
        "detect/3.0.0",
        "functional/0.1.0",
    ]

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")

    def generate(self):
        SConsDeps(self).generate()
