#ifndef FT_CONTAINERS_KVP_HPP
#define FT_CONTAINERS_KVP_HPP
#include <iostream>

using namespace std;

namespace ft {
template <typename K, typename V>
class kvp {
   public:
	K key;
	V value;
	/*
	INFO Construct an empty kvp
	*/
	kvp() : key(), value(){};
	/*
	INFO Construct a kvp with <dkey> and <dvalue>
	*/
	kvp(K const &dkey, V const &dvalue)
		: key(dkey), value(dvalue){};
	/*
	INFO Copy <other>
	*/
	kvp(kvp<K, V> const &other) {
		*this = other;
	};
	/*
	INFO Destruct the kvp
	*/
	~kvp(void){};
	/*
	INFO Copy <other>
	*/
	kvp &operator=(kvp const &rhs) {
		this->key = rhs.key;
		this->value = rhs.value;
		return *this;
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool operator==(ft::kvp<K, V> const &rhs) {
		return this->key == rhs.key && this->value == rhs.value;
	};
	/*
	INFO Check if<this> != <other>
	*/
	bool operator!=(ft::kvp<K, V> const &rhs) {
		return this->key != rhs.key || this->value != rhs.value;
	};
	/*
	INFO Check if <this> < <other>
	*/
	bool operator<(ft::kvp<K, V> const &rhs) {
		return this->key < rhs.key ||
			   (this->key == rhs.key && this->value < rhs.value);
	};
	/*
	INFO Check if <this> <= <other>
	*/
	bool operator<=(ft::kvp<K, V> const &rhs) {
		return this->key < rhs.key ||
			   (this->key == rhs.key && this->value < rhs.value) ||
			   (this->key == rhs.key && this->value == rhs.value);
	};
	/*
	INFO Check if <this> > <other>
	*/
	bool operator>(ft::kvp<K, V> const &rhs) {
		return this->key > rhs.key ||
			   (this->key == rhs.key && this->value > rhs.value);
	};
	/*
	INFO Check if <this> >= <other>
	*/
	bool operator>=(ft::kvp<K, V> const &rhs) {
		return this->key > rhs.key ||
			   (this->key == rhs.key && this->value > rhs.value) ||
			   (this->key == rhs.key && this->value == rhs.value);
	};
	/*
	INFO Check if <this> == <other>
	*/
	bool compare(ft::kvp<K, V> const &lhs, ft::kvp<K, V> const &rhs) {
		return lhs == rhs;
	};
	/*
	INFO Print the kvp
	*/
	void print(void) {
		cout << "Key: " << this->key << " Value: " << this->value << endl;
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
INFO Make a new kvp containing <key> and <value>
*/
kvp<K, V> make_kvp(K dkey, V dvalue) {
	return kvp<K, V>(dkey, dvalue);
};
}  // namespace ft
#endif
