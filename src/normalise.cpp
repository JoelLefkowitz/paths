

#include "normalise.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "components.hpp"
#include "vectors.tpp"
#include "words.hpp"
#include <detect/constants.hpp>
#include <initializer_list>
#include <string>
#include <vector>

std::vector<std::string> paths::normalise(const std::vector<std::string> &paths) {
    std::vector<std::string> filtered;

    auto contentful = filter(paths, {"", "."});

    for (auto i = contentful.begin(); i != contentful.end(); ++i) {
        if (*i == ".." && !filtered.empty() && filtered.back() != "..") {
            filtered.pop_back();
        } else {
            filtered.push_back(*i);
        }
    }

    return filtered.empty() ? std::vector<std::string>({"."}) : filtered;
}

std::string paths::normpath(const std::string &path) {
    auto normalised = normalise(split(path, platform::sep));

    if (absolute(path)) {
        std::vector<std::string> equivalent = {};

        for (auto i = normalised.begin(); i != normalised.end(); ++i) {
            if (*i != ".." || !equivalent.empty()) {
                equivalent.push_back(*i);
            }
        }

        normalised = equivalent;

        if (normalised == std::vector<std::string>({"."})) {
            normalised = {};
        }
    }

    auto joined = join(normalised, platform::sep);

    std::vector<char> chars(path.begin(), path.end());

    if (count_leading(chars, platform::sep) == 2) {
        joined = std::string(2, platform::sep) + joined;
    }

    else if (absolute(path)) {
        joined = platform::sep + joined;
    }

    auto prefix = drive(path);
    return starts_with(prefix, "//") ? joined : prefix + joined;
}
