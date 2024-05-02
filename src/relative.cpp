#include "relative.hpp"
#include "absolute.hpp"
#include "chunks.hpp"
#include "detect.hpp"
#include "normalise.hpp"
#include "resolve.hpp"
#include "vectors.tpp"
#include <string>
#include <utility>
#include <vector>

std::string paths::relpath(const std::string &source, const std::string &target) {
    auto pair = trim_leading_matches(filter(segments(source), {"."}), filter(segments(target), {"."}));

    auto merged = std::vector<std::string>(pair.first.size(), "..");
    merged.insert(merged.end(), pair.second.begin(), pair.second.end());

    return normpath(join(merged, platform::sep));
}

bool paths::relative(const std::string &path) { return !absolute(path); }
