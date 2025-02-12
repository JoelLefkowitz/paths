import os

from conan import ConanFile
from conan.tools.files import copy
from conan.tools.scons import SConsDeps
from conan.tools.layout import basic_layout


class PathsConan(ConanFile):
    name = "paths"
    description = "Cross platform OS path operations and executable path retrieval."
    version = "0.0.0"
    license = "MIT"

    url = "https://github.com/conan-io/conan-center-index"
    homepage = "https://github.com/JoelLefkowitz/paths"

    topics = (
        "path",
        "runtime",
        "relative",
        "absolute",
        "source",
    )

    requires = ("detect/3.0.0",)

    def package_info(self):
        self.cpp_info.libs = [self.name]

    def build_requirements(self):
        self.test_requires("gtest/1.12.1")

    def export_sources(self):
        for source in [
            "conanfile.py",
            "SConstruct.py",
            "src/*.[cht]pp",
        ]:
            copy(
                self,
                source,
                self.recipe_folder,
                self.export_sources_folder,
            )

    def generate(self):
        SConsDeps(self).generate()

    def build(self):
        self.run("scons build")

    def package(self):
        copy(
            self,
            "*.[ht]pp",
            f"{self.build_folder}/src",
            f"{self.package_folder}/include/{self.name}",
        )
        copy(
            self,
            "*.a",
            f"{self.build_folder}/dist",
            f"{self.package_folder}/lib",
        )
