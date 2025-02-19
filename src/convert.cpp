

#include "convert.hpp"
#include "components.hpp"
#include <algorithm>
#include <detect/constants.hpp>
#include <string>

std::string paths::posix_path(std::string path) {
    std::replace(path.begin(), path.end(), paths::windows_sep, paths::posix_sep);

    return letter_drive(path).empty() ? path : path.substr(2, path.length());
}

std::string paths::windows_path(std::string path) {
    std::replace(path.begin(), path.end(), paths::posix_sep, paths::windows_sep);

    return path;
}

std::string paths::platform_path(const std::string &path) {
    return platform::os == platform::Windows ? windows_path(path) : posix_path(path);
}
