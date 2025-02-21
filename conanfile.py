import os
from conan import ConanFile
from conan.tools.scons import SConsDeps
from conan.tools.layout import basic_layout


class PathsConan(ConanFile):
    requires = ("detect/3.0.0",)

    def layout(self):
        basic_layout(self, src_folder="src")

    def generate(self):
        SConsDeps(self).generate()

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")
