#ifndef LESS_HPP
#define LESS_HPP
#include <iostream>

namespace ft {
template <class T>
struct less : std::binary_function<T, T, bool> {
	bool operator()(const T& x, const T& y) const { return x < y; }
};
}  // namespace ft

#endif
