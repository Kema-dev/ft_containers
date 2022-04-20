#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP
#include <iostream>

namespace ft {
template <typename K, typename V>
class pair {
   public:
	K key;
	V value;
	/*
	INFO Construct an empty pair
	*/
	pair() : key(), value(){};
	/*
	INFO Construct a pair with <dkey> and <dvalue>
	*/
	pair(K const &dkey, V const &dvalue)
		: key(dkey), value(dvalue){};
	/*
	INFO Copy <other>
	*/
	pair(pair<K, V> const &other) {
		*this = other;
	};
	/*
	INFO Destruct the pair
	*/
	~pair(void){};
	/*
	INFO Copy <other>
	*/
	pair &operator=(pair const &rhs) {
		this->key = rhs.key;
		this->value = rhs.value;
		return *this;
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool operator==(ft::pair<K, V> const &rhs) {
		return this->key == rhs.key && this->value == rhs.value;
	};
	/*
	INFO Check if<this> != <other>
	*/
	bool operator!=(ft::pair<K, V> const &rhs) {
		return this->key != rhs.key || this->value != rhs.value;
	};
	/*
	INFO Check if <this> < <other>
	*/
	bool operator<(ft::pair<K, V> const &rhs) {
		return this->key < rhs.key ||
			   (this->key == rhs.key && this->value < rhs.value);
	};
	/*
	INFO Check if <this> <= <other>
	*/
	bool operator<=(ft::pair<K, V> const &rhs) {
		return this->key < rhs.key ||
			   (this->key == rhs.key && this->value < rhs.value) ||
			   (this->key == rhs.key && this->value == rhs.value);
	};
	/*
	INFO Check if <this> > <other>
	*/
	bool operator>(ft::pair<K, V> const &rhs) {
		return this->key > rhs.key ||
			   (this->key == rhs.key && this->value > rhs.value);
	};
	/*
	INFO Check if <this> >= <other>
	*/
	bool operator>=(ft::pair<K, V> const &rhs) {
		return this->key > rhs.key ||
			   (this->key == rhs.key && this->value > rhs.value) ||
			   (this->key == rhs.key && this->value == rhs.value);
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool compare(ft::pair<K, V> const &lhs, ft::pair<K, V> const &rhs) {
		return lhs == rhs;
	};
	/*
	INFO Print the pair
	*/
	void print(void) {
		std::cout << "Key: " << this->key << " Value: " << this->value << std::endl;
	};
	/*
	INFO Standard comparison function
	*/
	bool less(K &lhs, K &rhs) {
		return lhs < rhs;
	};
};
template <typename K, typename V>
/*
INFO Make a new pair containing <key> and <value>
*/
pair<K, V> make_pair(K dkey, V dvalue) {
	return pair<K, V>(dkey, dvalue);
};
}  // namespace ft
#endif
