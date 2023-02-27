#ifndef TEST_PATHS_VECTORS_H
#define TEST_PATHS_VECTORS_H

#include <vector>

namespace test {
    template <typename T>
    std::vector<T> concat(const std::vector<T> &x, const T &y);

    template <typename T>
    std::vector<T> concat(const std::vector<T> &x, const std::vector<T> &y);
} // namespace test

// cppclean-disable-next-line
#include "vectors.tpp"

#endif
