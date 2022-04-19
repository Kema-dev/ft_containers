#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP
#include <sys/types.h>

#include <deque>
#include <iostream>

namespace ft {
template <typename T>
class ReverseIterator {
   public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef ReverseIterator<T> reverse_iterator;
	// typedef ReverseIterator<const T> const_reverse_iterator;

   protected:
	pointer _array;

   public:
	ReverseIterator(pointer array)
		: _array(array) {}
	ReverseIterator(reverse_iterator& it) : _array(it._array) {}

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
