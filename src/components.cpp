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
#include <iostream>
#include <string>

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

std::string paths::windows_letter_drive(const std::string &path) {
    return (path.length() > 1 && path.at(0) != platform::sep && path.at(1) == ':') ? path.substr(0, 2) : "";
}

std::string paths::windows_domain_drive(const std::string &path) {
    auto raw = split(path, "/");

    std::vector<std::string> chunks;

    for (auto i : raw) {
        if (i != "") {
            chunks.push_back(i);
        }
    }

    if (starts_with(path, "//") && !starts_with(path, "///") && chunks.size() > 2) {
        return "//" + chunks.front() + "/" + chunks.at(1);
    }

    return "";
}

std::string paths::drive(const std::string &path) {
    if (platform::os == platform::Windows) {
        auto letter = windows_letter_drive(path);
        return letter.empty() ? windows_domain_drive(path) : letter;
    }

    return "";
}
