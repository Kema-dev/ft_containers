#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP
#include <sys/types.h>

#include <deque>
#include <iostream>
#include "../../Tools/RBT.hpp"

namespace ft {
template <typename K, typename V>
class MapReverseIterator {
protected:
	RBT<K, V>* current;
	RBT<K, V>* root;
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
	// typedef MapReverseIterator<const K, V> iterator;
	// typedef MapReverseIterator<const K, const V> const_iterator;
	typedef MapReverseIterator<const K, V> reverse_iterator;
	typedef MapReverseIterator<const K, const V> const_reverse_iterator;

	MapReverseIterator(void) {
		current = NULL;
		root = NULL;
	};
	MapReverseIterator(RBT<K, V>* _current, RBT<K, V>* _root) {
		current = _current;
		root = _root;
	};
	MapReverseIterator(const reverse_iterator& other) {
		current = other.current;
		root = other.root;
	};
	~MapReverseIterator(void) {
	};
	reverse_iterator& operator=(const reverse_iterator& other) {
		current = other.current;
		root = other.root;
		return (*this);
	};
	reverse_iterator& operator++(void) {
		current = current->next;
		return (*this);
	};
	reverse_iterator operator++(int) {
		reverse_iterator tmp = *this;
		current = current->next;
		return (tmp);
	};
	reverse_iterator& operator--(void) {
		current = current->prev;
		return (*this);
	};
	reverse_iterator operator--(int) {
		reverse_iterator tmp = *this;
		current = current->prev;
		return (tmp);
	};
	reference operator*(void) {
		return (current->value);
	};
	pointer operator->(void) {
		return (&(current->value));
	};
	bool operator==(const reverse_iterator& other) {
		return (current == other.current);
	};
	bool operator!=(const reverse_iterator& other) {
		return (current != other.current);
	};
	bool operator>(const reverse_iterator& other) {
		return (current > other.current);
	};
	bool operator<(const reverse_iterator& other) {
		return (current < other.current);
	};
	bool operator>=(const reverse_iterator& other) {
		return (current >= other.current);
	};
	bool operator<=(const reverse_iterator& other) {
		return (current <= other.current);
	};
};
} // namespace ft

#endif
