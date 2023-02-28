#include "vectors.hpp"
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
std::vector<T> paths::concat(const std::vector<T> &vec, const T &suffix) {
    std::vector<T> copy(vec);
    copy.push_back(suffix);
    return copy;
}

template <typename T>
std::vector<T> paths::concat(
    const std::vector<T> &vec,
    const std::vector<T> &suffix
) {
    std::vector<T> copy(vec);
    copy.insert(copy.end(), suffix.begin(), suffix.end());
    return copy;
}

template <typename T>
std::vector<T> paths::reverse(const std::vector<T> &vec) {
    std::vector<T> copy;

    auto size = --vec.begin();

    for (auto i = --vec.end(); i != size; --i) {
        copy.push_back(*i);
    }

    return copy;
}

template <typename T>
bool paths::contains(const std::vector<T> &vec, const T &x) {
    return std::any_of(vec.begin(), vec.end(), [&x](const T &y) {
        return x == y;
    });
}

template <typename T>
std::vector<T> paths::filter(
    const std::vector<T> &vec,
    const std::vector<T> &targets
) {
    std::vector<T> copy;

    std::copy_if(
        vec.begin(),
        vec.end(),
        std::back_inserter(copy),
        [&targets](const T &x) { return !contains(targets, x); }
    );

    return copy;
}

template <typename T>
size_t paths::count_leading(const std::vector<T> &vec, const T &prefix) {
    std::size_t count = 0;

    for (size_t e = vec.size(); count != e; ++count) {
        if (vec[count] != prefix) {
            break;
        }
    }

    return count;
}

template <typename T>
size_t paths::count_trailing(const std::vector<T> &vec, const T &suffix) {
    return count_leading(reverse(vec), suffix);
}

template <typename T>
std::pair<std::vector<T>, std::vector<T>> paths::trim_leading_matches(
    const std::vector<T> &x,
    const std::vector<T> &y
) {
    auto pair = trim_trailing_matches(reverse(x), reverse(y));
    return {reverse(pair.first), reverse(pair.second)};
}

template <typename T>
std::pair<std::vector<T>, std::vector<T>> paths::trim_trailing_matches(
    std::vector<T> x,
    std::vector<T> y
) {
    auto size = std::min(x.size(), y.size());

    for (size_t i = 0; i != size; ++i) {
        if (x.back() != y.back()) {
            break;
        }

        x.pop_back();
        y.pop_back();
    }

    return {x, y};
}
