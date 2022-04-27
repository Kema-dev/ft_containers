#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP
#include <sys/types.h>

#include <deque>
#include <iostream>

namespace ft {
template <typename T>
class VectorReverseIterator {
   public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	// typedef VectorIterator<T> iterator;
	// typedef VectorIterator<const T> const_iterator;
	typedef VectorReverseIterator<T> reverse_iterator;
	typedef VectorReverseIterator<const T> const_reverse_iterator;

   protected:
	pointer _array;

   public:
	VectorReverseIterator(pointer array)
		: _array(array) {}
	VectorReverseIterator(reverse_iterator& it) : _array(it._array) {}

	reverse_iterator& operator++() {
		_array--;
		return *this;
	}
	reverse_iterator operator++(int) {
		reverse_iterator tmp = *this;
		++*this;
		return tmp;
	}
	reverse_iterator& operator--() {
		_array++;
		return *this;
	}
	reverse_iterator operator--(int) {
		reverse_iterator tmp = *this;
		--*this;
		return tmp;
	}
	reverse_iterator& operator+=(difference_type n) {
		_array -= n;
		return *this;
	}
	reverse_iterator operator+(difference_type n) const {
		reverse_iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	reverse_iterator& operator-=(difference_type n) {
		_array += n;
		return *this;
	}
	reverse_iterator operator-(difference_type n) const {
		reverse_iterator tmp = *this;
		tmp -= n;
		return tmp;
	}
};
}  // namespace ft

#endif
