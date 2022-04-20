#ifndef PAIR_HPP
#define PAIR_HPP
#include <iostream>

#include "Less.hpp"

namespace ft {
template <typename K, typename V>
class pair {
   public:
	const K key;
	V value;
	/*
	INFO Construct an empty pair
	*/
	pair() : key(), value(){};
	/*
	INFO Construct a pair with <dkey> and <dvalue>
	*/
	pair(K const& dkey, V const& dvalue)
		: key(dkey), value(dvalue){};
	/*
	INFO Copy <other>
	*/
	pair(ft::pair<const K, V> const& other)
		: key(other.key), value(other.value){};
	/*
	INFO Destruct the pair
	*/
	~pair(void){};
	/*
	INFO Copy <other>
	*/
	pair &operator=(ft::pair<const K, V> const& rhs) {
		this->key = rhs.key;
		this->value = rhs.value;
		return *this;
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool operator==(ft::pair<const K, V> const& rhs) {
		return this->key == rhs.key && this->value == rhs.value;
	};
	/*
	INFO Check if<this> != <other>
	*/
	bool operator!=(ft::pair<const K, V> const& rhs) {
		return this->key != rhs.key || this->value != rhs.value;
	};
	/*
	INFO Check if <this> < <other>
	*/
	bool operator<(ft::pair<const K, V> const& rhs) {
		return this->key < rhs.key ||
			   (this->key == rhs.key && this->value < rhs.value);
	};
	/*
	INFO Check if <this> <= <other>
	*/
	bool operator<=(ft::pair<const K, V> const& rhs) {
		return this->key < rhs.key ||
			   (this->key == rhs.key && this->value < rhs.value) ||
			   (this->key == rhs.key && this->value == rhs.value);
	};
	/*
	INFO Check if <this> > <other>
	*/
	bool operator>(ft::pair<const K, V> const& rhs) {
		return this->key > rhs.key ||
			   (this->key == rhs.key && this->value > rhs.value);
	};
	/*
	INFO Check if <this> >= <other>
	*/
	bool operator>=(ft::pair<const K, V> const& rhs) {
		return this->key > rhs.key ||
			   (this->key == rhs.key && this->value > rhs.value) ||
			   (this->key == rhs.key && this->value == rhs.value);
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool compare(ft::pair<const K, V> const& lhs, ft::pair<const K, V> const& rhs) {
		return lhs == rhs;
	};
	/*
	INFO Print the pair
	*/
	void print(void) {
		std::cout << "Key: " << this->key << " Value: " << this->value << std::endl;
	};
	const K& first(void) const {
		return this->key;
	};
	const V& second(void) const {
		return this->value;
	};
};
template <typename K, typename V>
/*
INFO Make a new pair containing <key> and <value>
*/
pair<const K, V> make_pair(K dkey, V dvalue) {
	return pair<const K, V>(dkey, dvalue);
};
}  // namespace ft
#endif
