// ʕ •ᴥ•ʔ Paths - components.cpp ʕ•ᴥ• ʔ
// Cross platform OS path operations and executable path retrieval.
// https://github.com/joellefkowitz/paths
// Version: 0.1.0
// License: MIT

#include "components.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include "resolve.hpp"
#include "vectors.hpp"
#include "words.hpp"
#include <cstddef>
#include <string>

std::string paths::letter_drive(const std::string &path) {
    if (path.length() > 1 && path[1] == ':') {
        return path.substr(0, 2);
    }

    return "";
}

std::string paths::domain_drive(const std::string &path) {
    auto chunks = split(path, "/");

    if (starts_with(path, "//") && !starts_with(path, "///") && chunks.size() > 2) {
        return "//" + chunks.front() + "/" + chunks[1];
    }

    return "";
}

std::string paths::drive(const std::string &path) {
    if (platform::os == platform::Windows) {
        auto letter = letter_drive(path);
        return letter.empty() ? domain_drive(path) : letter;
    }

    return "";
}

std::string paths::head(const std::string &path) {
    auto chunks = segments(path);
    return chunks.empty() ? "" : chunks.back();
}

std::string paths::tail(const std::string &path) {
    auto normalised = segments(path);

    if (!normalised.empty()) {
        normalised.pop_back();
    }

    auto joined = join(normalised, platform::sep);

    std::vector<char> chars(path.begin(), path.end());

    if (count_leading(chars, platform::sep) == 2) {
        return std::string(2, platform::sep) + joined;
    }

    return absolute(path) ? platform::sep + joined : joined;
}

std::string paths::extension(const std::string &path) {
    auto normalised = segments(path);

    if (!normalised.empty()) {
        auto chunks = split(normalised.back(), ".");
        auto size   = chunks.size();

        if (size > 1 && chunks[size - 2] != "") {
            return "." + chunks.back();
        }
    }

    return "";
}
