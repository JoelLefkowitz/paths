#include "vectors.hpp"
#include <vector>

template <typename T>
std::vector<T> test::concat(const std::vector<T> &x, const T &y) {
    std::vector<T> copy(x);
    copy.push_back(y);
    return copy;
}

template <typename T>
std::vector<T> test::concat(const std::vector<T> &x, const std::vector<T> &y) {
    std::vector<T> copy(x);
    copy.insert(copy.end(), y.begin(), y.end());
    return copy;
}
