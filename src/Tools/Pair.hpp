#ifndef PAIR_HPP
#define PAIR_HPP
#include <iostream>

#include "Less.hpp"

namespace ft {
template <typename K, typename V>
class pair {
   public:
	K first;
	V second;
	/*
	INFO Construct an empty pair
	*/
	pair() : first(), second(){};
	/*
	INFO Construct a pair with <dkey> and <dvalue>
	*/
	pair(const K& dkey, const V& dvalue)
		: first(dkey), second(dvalue){};
	/*
	INFO Copy <other>
	*/
	pair(ft::pair<K, V> const& other)
		: first(other.first), second(other.second){};
	/*
	INFO Destruct the pair
	*/
	~pair(void){};

	/*
	INFO Copy <rhs>
	*/
	pair<K, V> &operator=(ft::pair<K, V> const& rhs) {
        first = rhs.first;
        second = rhs.second;
		return *this;
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool operator==(ft::pair<K, V> const& rhs) {
		return this->first == rhs.first && this->second == rhs.second;
	};
	/*
	INFO Check if<this> != <other>
	*/
	bool operator!=(ft::pair<K, V> const& rhs) {
		return this->first != rhs.first || this->second != rhs.second;
	};
	/*
	INFO Check if <this> < <other>
	*/
	bool operator<(ft::pair<K, V> const& rhs) {
		return this->first < rhs.first ||
			   (this->first == rhs.first && this->second < rhs.second);
	};
	/*
	INFO Check if <this> <= <other>
	*/
	bool operator<=(ft::pair<K, V> const& rhs) {
		return this->first < rhs.first ||
			   (this->first == rhs.first && this->second < rhs.second) ||
			   (this->first == rhs.first && this->second == rhs.second);
	};
	/*
	INFO Check if <this> > <other>
	*/
	bool operator>(ft::pair<K, V> const& rhs) {
		return this->first > rhs.first ||
			   (this->first == rhs.first && this->second > rhs.second);
	};
	/*
	INFO Check if <this> >= <other>
	*/
	bool operator>=(ft::pair<K, V> const& rhs) {
		return this->first > rhs.first ||
			   (this->first == rhs.first && this->second > rhs.second) ||
			   (this->first == rhs.first && this->second == rhs.second);
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool compare(ft::pair<K, V> const& lhs, ft::pair<K, V> const& rhs) {
		return lhs == rhs;
	};
	/*
	INFO Print the pair
	*/
	void print(void) {
		std::cout << "Key: " << this->first << " Value: " << this->second << std::endl;
	};
	// const K& first(void) const {
	// 	return this->first;
	// };
	// const V& second(void) const {
	// 	return this->second;
	// };
};
/*
INFO Make a new pair containing <first> and <second>
*/
template <typename K, typename V>
pair<K, V> make_pair(K dkey, V dvalue) {
	return pair<K, V>(dkey, dvalue);
};
}  // namespace ft
#endif
