from conan import ConanFile, tools

class Recipe(ConanFile):
    name = "paths"
    version = "0.1.0"

    license = "MIT"
    author = "Joel Lefkowitz joellefkowitz@hotmail.com"
    url = "https://github.com/JoelLefkowitz/paths"
    description = "Cross platform OS path operations and executable path retrieval."
    topics = ()

    exports_sources = 'src/*'
    
    def build(self):
        debug_opt = '--debug-build' if self.settings.build_type == 'Debug' else ''
        os.makedirs('build')

        with tools.chdir('build'):
            self.run('scons -C {}/src {}'.format(self.source_folder, debug_opt))
        
    def package(self):
        self.copy('*.hpp', 'include', src='src')
        
    def package_info(self):
        self.cpp_info.libs = []
