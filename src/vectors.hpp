#ifndef PATHS_VECTORS_HPP
#define PATHS_VECTORS_HPP

#include <cstddef>
#include <vector>

namespace paths {
    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const T &suffix);

    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const std::vector<T> &suffix);

    template <typename T>
    std::vector<T> reverse(const std::vector<T> &vec);

    template <typename T>
    bool contains(const std::vector<T> &vec, const T &x);

    template <typename T>
    std::vector<T> filter(const std::vector<T> &vec, const std::vector<T> &targets);

    template <typename T>
    size_t count_leading(const std::vector<T> &vec, const T &prefix);

    template <typename T>
    size_t count_trailing(const std::vector<T> &vec, const T &suffix);

    template <typename T>
    std::pair<std::vector<T>, std::vector<T>> trim_leading_matches(const std::vector<T> &x, const std::vector<T> &y);

    template <typename T>
    std::pair<std::vector<T>, std::vector<T>> trim_trailing_matches(std::vector<T> x, std::vector<T> y);
}

#endif
