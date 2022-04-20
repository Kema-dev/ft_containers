
#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <cmath>
#include <iostream>

#define EXPANDING_RATIO 2
#define AB = 0
#define A = 1
#define B = 2

#include "../Iterators/Iterator.hpp"
#include "../Iterators/ReverseIterator.hpp"
#include "../Tools/Exceptions.hpp"

namespace ft {

template <typename T, class alloc = allocator<T> >
class vector {
   public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef Iterator<T> iterator;
	typedef ReverseIterator<const T> reverse_iterator;
	typedef Iterator<const T> const_iterator;
	typedef ReverseIterator<const T> const_reverse_iterator;
	typedef alloc allocator_type;

   protected:
	alloc _alloc;
	T* _array;
	size_type _size;
	size_type _capacity;

   public:
	/*
	INFO Construct an empty vector
	INFO Combined both default constructor and allocator constructor
	*/
	vector(const allocator_type& alloct = allocator_type()) {
		_array = NULL;
		_size = 0;
		_capacity = 0;
		_alloc = alloct;
	};
	// INFO Construct a vector with <count> elements <value> (specifying allocator type <alloct>)
	explicit vector(size_type count, const T& value = T(), const allocator_type& alloct = allocator_type())
		: _alloc(alloct), _capacity(count * EXPANDING_RATIO), _size(count) {
		_array = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], value);
	};

	// INFO Construct a vector with elements <first> to <last> (specifying allocator type <alloc>)
	template <class InputIt>
	vector(InputIt first, InputIt last, const allocator_type& alloct = allocator_type())
		: _alloc(alloct) {
		if (first > last)
			throw std::length_error("ft::vector::vector : first > last");
		if (first == last) {
			_array = NULL;
			_size = 0;
			_capacity = 0;
		} else {
			size_type delta = last - first;
			_capacity = delta * EXPANDING_RATIO;
			_array = _alloc.allocate(_capacity);
			_size = delta;
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(&_array[i], *first);
				first++;
			}
		}
	};
	// INFO Construct a vector from <other>
	vector(const vector& other) {
		_capacity = other._capacity;
		_array = _alloc.allocate(_capacity);
		_size = other._size;
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], other._array[i]);
	};
	// INFO Construct a vector from <other> specifying allocator type <alloc>
	vector(const vector& other, const allocator_type& alloct)
		: _alloc(alloct) {
		_capacity = other._capacity;
		_array = _alloc.allocate(_capacity);
		_size = other._size;
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], other._array[i]);
	};
	// INFO Destruct the vector
	virtual ~vector() {
		for (size_type i = 0; i < _size; i++) {
			_alloc.destroy(&_array[i]);
		}
		_alloc.deallocate(_array, _capacity);
	};
	// INFO Copy vector <rhs>
	vector& operator=(const vector& rhs) {
		if (this != &rhs) {
			clear();
			_alloc.deallocate(_array, _capacity);
			_alloc = rhs._alloc;
			_capacity = rhs._capacity;
			_array = _alloc.allocate(_capacity);
			_size = rhs._size;
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(&_array[i], rhs._array[i]);
			}
		}
		return *this;
	};
	// INFO Assign <count> elements <value>
	void assign(size_type count, const T& value) {
		clear();
		if (count > _capacity) {
			_alloc.deallocate(_array, _capacity);
			_capacity = count * EXPANDING_RATIO;
			_array = _alloc.allocate(_capacity);
		}
		_size = count;
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], value);
	};
	// INFO Assign elements <first> to <last>
	template <class InputIt>
	void assign(InputIt first, InputIt last) {
		if (first > last)
			throw std::length_error("ft::vector::assign : first > last");
		clear();
		if (first == last) {
			return;
		}
		size_type delta = last - first;
		if (delta > _capacity) {
			resize(delta);
		}
		_size = delta;
		for (size_type i = 0; i < _size; i++) {
			_alloc.construct(&_array[i], *first);
			first++;
		}
	};
	// INFO Get allocator
	allocator_type get_allocator() const {
		return _alloc;
	};
	/*
	INFO Get element <n> (_array[n])
	INFO Throws OutOfRangeException if <n> >= _size
	*/
	reference at(size_type n) {
		if (n >= _size) {
			throw OutOfRangeException();
		}
		return _array[n];
	};
	/*
	INFO Get element <n> (_array[n])
	INFO Undefined behavior if <n> >= _size
	*/
	reference operator[](size_type n) {
		return _array[n];
	};
	/*
	INFO Get first element
	INFO Undefined behavior if <n> >= _size
	*/
	reference front() {
		return _array[0];
	};
	/*
	INFO Get last element
	INFO Undefined behavior if <n> >= _size
	*/
	reference back() {
		return _array[_size - 1];
	};
	/*
	INFO Get _array
	INFO Undefined behavior if _size == 0
	*/
	T* data() {
		return _array;
	};
	// INFO Get iterator to first element
	iterator begin(void) {
		return iterator(_array);
	};
	// INFO Get iterator to last element
	iterator end(void) {
		return iterator(_array + _size);
	};
	// INFO Get const iterator to first element
	// const_iterator begin(void) const {
	// 	return const_iterator(_array);
	// };
	// INFO Get const iterator to last element
	// const_iterator end(void) const {
	// 	return const_iterator(_array + _size);
	// };
	// INFO Get reverse iterator to first element (reverse order)
	reverse_iterator rbegin(void) {
		return reverse_iterator(_array + _size - 1);
	};
	// INFO Get reverse iterator to last element (reverse order)
	reverse_iterator rend(void) {
		return reverse_iterator(_array - 1);
	};
	// INFO Get const reverse iterator to first element (reverse order)
	// const_reverse_iterator rbegin(void) const {
	// 	return const_reverse_iterator(_array + _size - 1);
	// };
	// INFO Get const reverse iterator to last element (reverse order)
	// const_reverse_iterator rend(void) const {
	// 	return const_reverse_iterator(_array - 1);
	// };
	// INFO Check if _size == 0
	bool empty(void) const {
		return _size == 0;
	};
	// INFO Get _size (number of elements)
	size_type size(void) {
		return _size;
	};
	// INFO Get theorical maximum allocable size
	size_type max_size(void) {
		return _alloc.max_size();
	};
	// INFO Reserve storage for <n> elements
	void reserve(size_type n) {
		if (n == 0) {
			n = 1;
		}
		if (n > _capacity) {
			_capacity = n;
			T* tmp = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(&tmp[i], _array[i]);
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _capacity);
			_array = tmp;
		}
	};
	// INFO Get _capacity (real storage size)
	size_type capacity(void) {
		return _capacity;
	};
	// INFO Clear vector's content
	void clear() {
		for (size_type i = 0; i < _size; i++) {
			_alloc.destroy(&_array[i]);
		}
		_size = 0;
	};
	// INFO Insert element <val> at position <pos>
	iterator insert(iterator pos, const T& val) {
		if (_size >= _capacity) {
			reserve(_capacity * EXPANDING_RATIO);
		}
		for (size_type i = _size; i > size_type(pos - this->begin()); i--) {
			_alloc.construct(&_array[i], _array[i - 1]);
			_alloc.destroy(&_array[i - 1]);
		}
		_alloc.construct(&_array[pos - this->begin()], val);
		_size++;
		return iterator(pos);
	};
	// INFO Insert <count> elements <value> at position <pos>
	void insert(iterator pos, size_type count, const T& value) {
		if (_size + count > _capacity) {
			reserve((_size + count) * EXPANDING_RATIO);
		}
		for (size_type i = _size; i > pos - this->begin(); i--) {
			_alloc.construct(&_array[i + count - 1], _array[i - 1]);
			_alloc.destroy(&_array[i - 1]);
		}
		for (size_type i = 0; i < count; i++) {
			_alloc.construct(&_array[pos - this->begin() + i], value);
		}
		_size += count;
	};
	// INFO Insert elements <first> to <last> at position <pos>
	template <class InputIt>
	void insert(iterator pos, InputIt first, InputIt last) {
		if (first == last) {
			return;
		} else if (first > last) {
			throw std::length_error("ft::Vector::insert : first > last");
		}
		size_type delta = last - first;
		if (_size + delta > _capacity) {
			reserve((_size + delta) * EXPANDING_RATIO);
		}
		for (size_type i = _size; i > pos - this->begin(); i--) {
			_alloc.construct(&_array[i + delta - 1], _array[i - 1]);
			_alloc.destroy(&_array[i - 1]);
		}
		for (size_type i = 0; i < delta; i++) {
			_alloc.construct(&_array[pos - this->begin() + i], *(first + i));
		}
		_size += delta;
	};
	// INFO Erase element at position <pos>
	iterator erase(iterator pos) {
		if (pos - this->begin() >= _size) {
			throw OutOfRangeException();
		}
		for (size_type i = pos - this->begin(); i < _size - 1; i++) {
			_alloc.construct(&_array[i], _array[i + 1]);
		}
		_alloc.destroy(&_array[_size - 1]);
		_size--;
		return iterator(_array + size_type(pos - this->begin()));
	};
	// INFO Erase elements from position <first> to position <last>
	iterator erase(iterator first, iterator last) {
		size_type delta = last - first;
		if (size_type(first - this->begin()) >= _size || size_type(last - this->begin()) >= _size) {
			throw OutOfRangeException();
		}
		for (size_type i = (size_type(first - this->begin())); i < _size - delta; i++) {
			_alloc.construct(&_array[i], _array[i + delta]);
		}
		for (size_type i = 0; i < delta; i++) {
			_alloc.destroy(&_array[_size - 1 - i]);
		}
		_size -= delta;
		return iterator(_array + size_type(first - this->begin()));
	};
	// INFO Add element <val> at end
	void push_back(const T& val) {
		if (_size >= _capacity) {
			reserve(_capacity * EXPANDING_RATIO);
		}
		_alloc.construct(&_array[_size], val);
		_size++;
	};
	// INFO Remove last element
	void pop_back() {
		_alloc.destroy(&_array[_size - 1]);
		_size--;
	};
	// INFO Resize vector
	void resize(size_type n, T val = T()) {
		if (n > _capacity) {
			_capacity = n;
			T* tmp = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(&tmp[i], _array[i]);
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _capacity);
			_array = tmp;
		}
		if (n > _size) {
			for (size_type i = _size; i < n; i++) {
				_alloc.construct(&_array[i], val);
			}
		}
		_size = n;
	};
	void swap(vector& v) {
		std::swap(_alloc, v._alloc);
		std::swap(_array, v._array);
		std::swap(_size, v._size);
		std::swap(_capacity, v._capacity);
	};
	// SECTION Custom
	int	lexicographical_compare(T const &a, T const &b) {
		for (size_t i = 0; i < a.size(); i++) {
			if (a[i] < b[i])
				return B;
			else if (a[i] > b[i])
				return A;
		}
		return AB;
	}
	// INFO Check if <this> == <v>
	bool operator==(const vector& v) const {
		if (_size != v._size) {
			return false;
		}
		for (size_type i = 0; i < _size; i++) {
			if (_array[i] != v._array[i]) {
				return false;
			}
		}
		return true;
	};
	// INFO Check if <this> != <v>
	bool operator!=(const vector& v) const {
		return !(*this == v);
	};
	// INFO Check if <this> < <v>
	bool operator<(const vector& v) const {
		if (_size < v._size) {
			return true;
		} else if (_size > v._size) {
			return false;
		}
		for (size_type i = 0; i < _size; i++) {
			if (_array[i] < v._array[i]) {
				return true;
			} else if (_array[i] > v._array[i]) {
				return false;
			}
		}
		return false;
	};
	// INFO Check if <this> <= <v>
	bool operator<=(const vector& v) const {
		return (*this < v || *this == v);
	};
	// INFO Check if <this> > <v>
	bool operator>(const vector& v) const {
		return !(*this <= v);
	};
	// INFO Check if <this> >= <v>
	bool operator>=(const vector& v) const {
		return !(*this < v);
	};
	// !SECTION Custom
};
}  // end namespace ft

#endif