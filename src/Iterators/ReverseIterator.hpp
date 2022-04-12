#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP
#include <deque>
#include <iostream>
#include <sys/types.h>

template <class T, class Distance = std::ptrdiff_t,
		  class Pointer = T*, class Reference = T&>
class ReverseIterator
{
	public:
		typedef ReverseIterator	self_type;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	private:
		pointer	_ptr;

	public:
		ReverseIterator() {
		};

		ReverseIterator(pointer ptr) : _ptr(ptr) {
		};

		ReverseIterator&	operator=(ReverseIterator const& ref) {
			_ptr = ref._ptr;
			return *this;
		}

		bool	operator==(ReverseIterator const& ref) {
			return *this == ref ? true : false;
		}

		bool	operator!=(ReverseIterator const& ref) {
			return this->_ptr != ref._ptr ? true : false;
		}

		self_type	operator++() { // ? prefix
			_ptr--;
			return *this;
		}

		self_type	operator++(int n) { // ? postfix
			if (n == 0)
				_ptr--;
			else {
				_ptr -= n;
			}
			return *this;
		}

		self_type	operator--() { // ? prefix
			_ptr++;
			return *this;
		}

		self_type	operator--(int n) { // ? postfix
			if (n == 0)
				_ptr++;
			else {
				_ptr += n;
			}
			return *this;
		}

		self_type operator+(int n) {
			self_type other = *this;
			for (int i = 0; i < n; i++)
				other._ptr--;
			return other;
		}

		self_type operator-(int n) {
			self_type other = *this;
			for (int i = 0; i < n; i++)
				other._ptr++;
			return other;
		}

		self_type operator+=(int n) {
			for (int i = 0; i < n; i++)
				_ptr--;
			return *this;
		}

		self_type operator-=(int n) {
			for (int i = 0; i < n; i++)
				_ptr++;
			return *this;
		}

		reference operator*(void) {
			return *_ptr;
		}

		pointer operator&(void) {
			return _ptr;
		}

		~ReverseIterator() {
		};
};

#endif
