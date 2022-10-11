// ʕ •ᴥ•ʔ Paths - normalise.cpp ʕ•ᴥ• ʔ
// OS specific path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "normalise.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "detect.hpp"
#include "relative.hpp"
#include "words.hpp"
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> paths::normalise(const std::vector<std::string> &paths) {
    std::vector<std::string> contentful;

    std::copy_if(
        paths.begin(),
        paths.end(),
        std::back_inserter(contentful),
        [](const std::string &x) { return x != "" && x != "."; }
    );

    std::vector<std::string> filtered;

    for (auto i = contentful.begin(); i != contentful.end(); ++i) {
        if (*i == ".." && !filtered.empty() && filtered.back() != "..") {
            filtered.pop_back();
        } else if (*i != ".." || !filtered.empty()) {
            filtered.push_back(*i);
        }
    }

    return filtered;
}

std::string paths::normpath(const std::string &path) {
    auto joined = join(normalise(split(path, platform::sep)), platform::sep);

    if (starts_with(path, "//") && !starts_with(path, "///")) {
        return "//" + joined;
    }

    if (absolute(path)) {
        return "/" + joined;
    }

    if (joined == "") {
        return ".";
    }

    return joined;
}
