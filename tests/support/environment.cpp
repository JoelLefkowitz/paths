#include "environment.hpp"
#include <cstdlib>
#include <string>

std::string test::environment(const std::string &name) {
    const char *lookup = std::getenv(name.c_str());

    if (!lookup) {
        throw std::runtime_error("Missing " + name + " environment variable");
    }

    return lookup;
}
