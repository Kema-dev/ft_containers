#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include <sys/types.h>

#include <deque>
#include <iostream>
#include "../../Tools/RBT.hpp"

namespace ft {
template <typename K, typename V>
class MapIterator {
protected:
	ft::pair<const K, V>* current;
	ft::pair<const K, V>* root;
public:
	typedef K key_type;
	typedef V mapped_type;
	typedef V value_type;
	typedef V* pointer;
	typedef V& reference;
	typedef const V* const_pointer;
	typedef const V& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef MapIterator<const K, V> iterator;
	typedef MapIterator<const K, const V> const_iterator;
	// typedef MapReverseIterator<const K, V> reverse_iterator;
	// typedef MapReverseIterator<const K, const V> const_reverse_iterator;


	MapIterator(void) {
		current = NULL;
		root = NULL;
	};
	MapIterator(RBT<const K, V>* _current, RBT<const K, V>* _root) {
		current = _current;
		root = _root;
	};
	MapIterator(const iterator& other) {
		current = other.current;
		root = other.root;
	};
	~MapIterator(void) {
	};
	iterator& operator=(const iterator& other) {
		current = other.current;
		root = other.root;
		return (*this);
	};
	iterator& operator++(void) {
		current = current->next;
		return (*this);
	};
	iterator operator++(int) {
		iterator tmp = *this;
		current = current->next;
		return (tmp);
	};
	iterator& operator--(void) {
		current = current->prev;
		return (*this);
	};
	iterator operator--(int) {
		iterator tmp = *this;
		current = current->prev;
		return (tmp);
	};
	reference operator*(void) {
		return (current->value);
	};
	pointer operator->(void) {
		return (&(current->value));
	};
	bool operator==(const iterator& other) {
		return (current == other.current);
	};
	bool operator!=(const iterator& other) {
		return (current != other.current);
	};
	bool operator>(const iterator& other) {
		return (current > other.current);
	};
	bool operator<(const iterator& other) {
		return (current < other.current);
	};
	bool operator>=(const iterator& other) {
		return (current >= other.current);
	};
	bool operator<=(const iterator& other) {
		return (current <= other.current);
	};
	const K& first(void) {
		return (current->first());
	};
	const V& second(void) {
		return (current->second());
	};
};
} // namespace ft

#endif
