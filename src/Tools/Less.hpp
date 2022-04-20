#ifndef LESS_HPP
#define LESS_HPP
#include <iostream>

namespace ft {
template <typename K>
class less {
public:
	bool operator()(K const &lhs, K const &rhs) const {
		return lhs < rhs;
	}
};
}  // namespace ft

#endif
