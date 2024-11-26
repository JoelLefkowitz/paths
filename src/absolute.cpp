#include "absolute.hpp"
#include "realtime.hpp"
#include "resolve.hpp"
#include "words.hpp"
#include <detect/constants.hpp>
#include <string>
#include <vector>

std::string paths::abspath(const std::string &path) { return absolute(path) ? path : resolve({dirpath(), path}); }

bool paths::absolute(const std::string &path) { return starts_with(path, platform::sep); }
