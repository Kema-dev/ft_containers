#ifndef FT_CONTAINERS_KVP_HPP
# define FT_CONTAINERS_KVP_HPP
# include <iostream>

using namespace std;

namespace ft {
	template<typename K, typename V>
	class kvp
	{
	public:
		//	*	Variables
		K	key;
		V	value;
		//	*	Constructors
		kvp(): key(), value() {
		};
		kvp(K const &dkey, V const &dvalue)
			: key(dkey), value(dvalue) {
		};
		kvp(kvp<K, V> const &other) {
			*this = other;
		};
		//	*	Destructor
		~kvp(void) {
		};
		//	*	Other member functions
		kvp&	operator=(kvp const& rhs) {
			this->key = rhs.key;
			this->value = rhs.value;
			return *this;
		};
		//	*	Comparison operators
		bool	operator==(ft::kvp<K, V> const &rhs) {
			return this->key == rhs.key && this->value == rhs.value;
		};
		bool	operator!=(ft::kvp<K, V> const &rhs) {
			return this->key != rhs.key || this->value != rhs.value;
		};
		bool	operator<(ft::kvp<K, V> const &rhs) {
			return this->key < rhs.key ||
					(this->key == rhs.key && this->value < rhs.value);
		};
		bool	operator<=(ft::kvp<K, V> const &rhs) {
			return this->key < rhs.key ||
					(this->key == rhs.key && this->value < rhs.value) ||
					(this->key == rhs.key && this->value == rhs.value);
		};
		bool	operator>(ft::kvp<K, V> const &rhs) {
			return this->key > rhs.key ||
					(this->key == rhs.key && this->value > rhs.value);
		};
		bool	operator>=(ft::kvp<K, V> const &rhs) {
			return this->key > rhs.key ||
					(this->key == rhs.key && this->value > rhs.value) ||
					(this->key == rhs.key && this->value == rhs.value);
		};
		bool	compare(ft::kvp<K, V> const &lhs, ft::kvp<K, V> const &rhs) {
			if (lhs == rhs) {
				return false;
			}
			return true;
		};
		//	*	Printing
		void	print(void) {
			cout << "Key: " << this->key << " Value: " << this->value << endl;
		};
		// ostream&	operator<<(ostream &o, ft::kvp<K, V> const &rhs) {
		// 	o << "Key: " << rhs.key << " Value: " << rhs.value;
		// 	return o;
		// };
	};
	template<typename K, typename V>
	kvp<K, V> make_kvp(K dkey, V dvalue) {
		return kvp<K, V>(dkey, dvalue);
	};
	template<typename K, typename V>
	bool	less(ft::kvp<K, V> &lhs, ft::kvp<K, V> &rhs) {
		if (lhs < rhs) {
			return true;
		}
		return false;
	};
}
#endif
