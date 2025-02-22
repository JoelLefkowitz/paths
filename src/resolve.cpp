

#include "resolve.hpp"
#include "chunks.hpp"
#include "normalise.hpp"
#include <cstddef>
#include <detect/constants.hpp>
#include <string>

std::string paths::resolve(const std::vector<std::string> &paths) {
    return join(normalise(paths), platform::sep);
}

std::vector<std::string> paths::segments(const std::string &path) {
    auto chunks = split(normpath(path), platform::sep);

    std::vector<std::string> filtered;

    auto size = chunks.size();

    for (std::size_t i = 0; i != size; ++i) {
        if (!chunks[i].empty() || (0 < i && i < size && !chunks[i - 1].empty() && !chunks[i + 1].empty())) {
            filtered.push_back(chunks[i]);
        }
    }

    return filtered;
}
