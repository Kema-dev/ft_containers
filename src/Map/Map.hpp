
#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP
#include <cmath>
#include <iostream>

#include "../Iterators/Iterator.hpp"
#include "../Iterators/ReverseIterator.hpp"
#include "../Tools/RBT.hpp"

namespace ft {

template <class K, class V, class Compare = typename ft::pair<K, V>::less(), class Allocator = std::allocator<ft::pair<const K, V> > >
class map {
   public:
	typedef K key_type;
	typedef V value_type;
	typedef Compare value_compare;
	typedef ft::pair<const K, V> pair_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef const value_type* const_pointer;
	typedef const value_type& const_reference;
	typedef Allocator allocator_type;
	typedef Compare key_compare;

   protected:
	value_compare comp;
	allocator_type alloc;
	RBT<K, V>* root;

   public:
	// INFO Construct an empty map
	map(void) {
		root = NULL;
		alloc = allocator_type();
		comp = value_compare();
	};
	// INFO Construct a map with comparison function <dcomp> and allocator type <dalloc>
	map(const Compare& compt, const allocator_type& alloct = allocator_type()) {
		root = NULL;
		comp = compt;
		alloc = alloct;
	};
	// INFO Construct a map containing elements <first> to <last> with comparison function <dcomp> and allocator type <dalloc>
	template <class InputIt>
	map(InputIt first, InputIt last, const Compare& compt = Compare(), const Allocator& alloct = Allocator()) {
		root = NULL;
		comp = compt;
		alloc = alloct;
		for (InputIt it = first; it != last; it++)
			insert(*it);
	};
	// INFO Copy <other>
	map(const map& other) {
		root = NULL;
		comp = other.comp;
		alloc = other.alloc;
		for (const_iterator it = other.begin(); it != other.end(); it++)
			insert(*it);
	};
	// INFO Destruct the map
	~map(void) {
		clear();
	};
	// INFO Copy <other>
	map& operator=(const map& other) {
		if (this != &other) {
			clear();
			comp = other.comp;
			alloc = other.alloc;
			for (const_iterator it = other.begin(); it != other.end(); it++)
				insert(*it);
		}
		return *this;
	};
	// INFO Get the allocator type
	allocator_type get_allocator(void) const {
		return alloc;
	};
	// INFO Get the value of the first pair matching <key>
	V& at(const K& key) {
		return find(key)->second;
	};
	// INFO Get the value of the first pair matching <key>
	const V& at(const K& key) const {
		return find(key)->second;
	};
	// INFO Get the value of the first pair matching <key> and insert it if it doesn't exist
	V& operator[](const K& key) {
		return insert(value_type(key, T())).first->second;
	};
	// INFO Get the begin
	iterator begin(void) {
		return *root;
	};
	// INFO Get the begin (const)
	const_iterator begin(void) const {
		return const_iterator(root->getRoot());
	};
	// INFO Get the end
	iterator end(void) {
		return iterator(NULL);
	};
	// INFO Get the end (const)
	const_iterator end(void) const {
		return const_iterator(NULL);
	};
	// INFO Get the reverse begin
	reverse_iterator rbegin(void) {
		return reverse_iterator(end());
	};
	// INFO Get the reverse begin (const)
	const_reverse_iterator rbegin(void) const {
		return const_reverse_iterator(end());
	};
	// INFO Get the reverse end
	reverse_iterator rend(void) {
		return reverse_iterator(begin());
	};
	// INFO Get the reverse end (const)
	const_reverse_iterator rend(void) const {
		return const_reverse_iterator(begin());
	};
	// INFO Check if the map is empty
	bool empty(void) const {
		return root.empty();
	};
	// INFO Get the size
	size_type size(void) const {
		return root.size();
	};
	// INFO Get the maximum size
	size_type max_size(void) const {
		return alloc.max_size();
	};
	// INFO Clear
	void clear(void) {
		root.clear();
	};
	// INFO Insert <value>
	iterator insert(const value_type& value) {
		return root.add(value);
	};
	// TODO WTF is this
	// iterator insert(iterator hint, const value_type& value ) {
	// 	return root.add(hint, value);
	// };
	// INFO Insert <first> to <last>
	template <class InputIt>
	void insert(InputIt first, InputIt last) {
		for (InputIt it = first; it != last; it++)
			insert(*it);
	};
	// INFO Erase element <pos>
	void erase(iterator pos) {
		root.remove(pos);
	};
	// INFO Erase elements <first> to <last>
	void erase(iterator first, iterator last) {
		while (first != last)
			erase(first++);
	};
	// INFO Erase element with key <key>
	size_type erase(const K& key) {
		return root.remove(key);
	};
	// INFO Swap <this> with <other>
	void swap(map& other) {
		root.swap(other.root);
	};
	// INFO Check if <key> is in the map
	size_type count(const K& key) const {
		if (root.find(key) == NULL)
			return 0;
		return 1;
	};
	// INFO Find element with key <key>
	iterator find(const K& key) {
		return iterator(root.find(key));
	};
	// INFO Find element with key <key> (const)
	const_iterator find(const K& key) const {
		return const_iterator(root.find(key));
	};
	// INFO Get the range of elements matching <key>
	pair_type<iterator, iterator> equal_range(const K& key) {
		return pair_type(find(key), find(key) + 1);
	};
	// INFO Get the range of elements matching <key> (const)
	pair_type<const_iterator, const_iterator> equal_range(const K& key) const {
		return pair_type(find(key), find(key) + 1);
	};
	// INFO Get the element directly lower than <key>
	iterator lower_bound(const K& key) {
		return iterator(root.lower_bound(key));
	};
	// INFO Get the element directly lower than <key> (const)
	const_iterator lower_bound(const K& key) const {
		return const_iterator(root.lower_bound(key));
	};
	// INFO Get the element directly greater or equal to <key>
	iterator upper_bound(const K& key) {
		return iterator(root.upper_bound(key));
	};
	// INFO Get the element directly greater or equal to <key> (const)
	const_iterator upper_bound(const K& key) const {
		return const_iterator(root.upper_bound(key));
	};
	// INFO Get the key comparison function
	key_compare key_comp() const {
		return comp;
	};
	// INFO Get the value comparison function
	pair_type value_comp() const {
		// REVIEW maybe not working
		return pair::less<value_type>();
	};
	// SECTION Custom
	// INFO Print the map as a tree
	void print(void) {
		root.print();
	};
	// !SECTION Custom
};
}  // end namespace ft

#endif