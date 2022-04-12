#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <deque>
#include <iostream>
#include <sys/types.h>

class Iterator
{
	private:
		typename Iterator::pointer	_ptr;
	public:
		typedef Iterator	self_type;
		Iterator() {
		};
		Iterator(pointer ptr) : _ptr(ptr) {
		};
		Iterator&	operator=(Iterator const& ref) {
			_ptr = ref._ptr;
			return *this;
		}
		bool	operator==(Iterator const& ref) {
			return *this == ref ? true : false;
		}
		bool	operator!=(Iterator const& ref) {
			return this->_ptr != ref._ptr ? true : false;
		}
		self_type	operator++() { // ? prefix
			_ptr++;
			return *this;
		}
		self_type	operator++(int n) { // ? postfix
			if (n == 0)
				_ptr++;
			else {
				_ptr += n;
			}
			return *this;
		}
		self_type	operator--() { // ? prefix
			_ptr--;
			return *this;
		}
		self_type	operator--(int n) { // ? postfix
			if (n == 0)
				_ptr--;
			else {
				_ptr += n;
			}
			return *this;
		}
		self_type operator+(int n) {
			self_type other = *this;
			for (int i = 0; i < n; i++)
				other._ptr++;
			return other;
		}
		self_type operator-(int n) {
			self_type other = *this;
			for (int i = 0; i < n; i++)
				other._ptr--;
			return other;
		}
		self_type operator+=(int n) {
			for (int i = 0; i < n; i++)
				_ptr++;
			return *this;
		}
		self_type operator-=(int n) {
			for (int i = 0; i < n; i++)
				_ptr--;
			return *this;
		}
		typename Iterator::reference operator*(void) {
			return *_ptr;
		}
		typename Iterator::pointer operator&(void) {
			return _ptr;
		}
		~Iterator() {
		};
};

#endif
