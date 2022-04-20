#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include <sys/types.h>

#include <deque>
#include <iostream>

namespace ft {
template <typename T>
class VectorIterator {
   public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef VectorIterator<T> iterator;
	typedef VectorIterator<const T> const_iterator;
	// typedef VectorReverseIterator<T> reverse_iterator;
	// typedef VectorReverseIterator<const T> const_reverse_iterator;

   protected:
	pointer _array;

   public:
	VectorIterator(pointer array) : _array(array) {}
	VectorIterator(const iterator& it) : _array(it._array) {}

	reference operator*() const { return *_array; }
	pointer operator->() const { return _array; }
	iterator& operator++() {
		_array++;
		return *this;
	}
	iterator operator++(int) {
		iterator tmp = *this;
		++*this;
		return tmp;
	}
	iterator& operator--() {
		_array--;
		return *this;
	}
	iterator operator--(int) {
		iterator tmp = *this;
		--*this;
		return tmp;
	}
	iterator& operator+=(difference_type n) {
		_array += n;
		return *this;
	}
	iterator operator+(difference_type n) const {
		iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	iterator& operator-=(difference_type n) {
		_array -= n;
		return *this;
	}
	iterator operator-(difference_type n) const {
		iterator tmp = *this;
		tmp -= n;
		return tmp;
	}
	difference_type operator-(const iterator& it) const { return _array - it._array; }
	reference operator[](difference_type n) const { return _array[n]; }
	bool operator==(const iterator& it) const { return _array == it._array; }
	bool operator!=(const iterator& it) const { return _array != it._array; }
	bool operator<(const iterator& it) const { return _array < it._array; }
	bool operator>(const iterator& it) const { return _array > it._array; }
	bool operator<=(const iterator& it) const { return _array <= it._array; }
	bool operator>=(const iterator& it) const { return _array >= it._array; }
};
}

#endif
