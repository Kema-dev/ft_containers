
#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP
#include <cmath>
#include <iostream>

// #include "../Iterators/Iterator.hpp"
#include "../Tools/RBT.hpp"

using namespace std;

namespace ft {

template<typename K>
class less {
public:
	bool	less(K &lhs, K &rhs) {
		return lhs < rhs;
	};
};

template<class K, class V, class Compare = ft::less<K>, class Allocator = allocator<ft::kvp<const K, V> > >
class map {
   public:
   key_type	Key
	typedef	T mapped_type;
	typedef std::pair<const Key, T> value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef const value_type* const_pointer;
	typedef const value_type& const_reference;
	typedef Allocator allocator_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::size_type size_type;

   protected:
	value_compare	comp;
	allocator_type	alloc;
	node<value_type>	*root;
	size_type			size;

   public:
	map(void ) : comp(), alloc(), root(NULL), size(0) {
	};
	map(const map& other) : comp(other.comp), alloc(other.alloc), root(other.root), size(other.size) {
	};
	value_compare	key_comp(class comp) {
		value_compare = comp;
	};
};
} // end namespace ft

#endif