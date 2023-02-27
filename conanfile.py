import os 
from conan import ConanFile, tools
from glob import glob

class Recipe(ConanFile):
    name = "paths"
    description = "Cross platform OS path operations and executable path retrieval."
    version = "0.1.0"

    license = "MIT"
    url = "https://github.com/JoelLefkowitz/paths"
    
    author = "Joel Lefkowitz joellefkowitz@hotmail.com"
    topics = ()

    exports_sources = "src/*"
    
    def build(self):
        self.run(f"g++ -c -std=c++11 {' '.join(glob('src/**/*.cpp', recursive=True))}")
        self.run(f"ar rcs paths.a {' '.join(glob('*.o', recursive=True))}")

    def package(self):
        tools.files.copy(self, "*.hpp", self.source_folder, os.path.join(self.package_folder, "include"))
        tools.files.copy(self, "*.a", self.build_folder, os.path.join(self.package_folder, "lib"))
        
    def package_info(self):
        self.cpp_info.libs = ["paths"]
