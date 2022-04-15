#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP
#include <sys/types.h>

#include <deque>
#include <iostream>

namespace ft {
template <typename T>
class Iterator {
   public:
	typedef typename deque<T>::iterator iterator;
   private:
	iterator _it;
	iterator _end;

   public:
	Iterator(deque<T>::iterator it, deque<T>::iterator end) : _it(it), _end(end) {}
	Iterator(const Iterator& src) : _it(src._it), _end(src._end) {}
	Iterator& operator=(const Iterator& rhs) {
		this->_it = rhs._it;
		this->_end = rhs._end;
		return *this;
	}
	~Iterator(void) {}
	int operator*(void) const {
		return *this->_it;
	}
	Iterator& operator&(void) {
		return *this;
	}
	bool operator==(const Iterator& rhs) const {
		return this->_it == rhs._it;
	}
	bool operator!=(const Iterator& rhs) const {
		return this->_it != rhs._it;
	}
	Iterator& operator++(void) {
		++this->_it;
		return *this;
	}
	Iterator& operator++(int) {
		++this->_it;
		return *this;
	}
	Iterator& operator--(void) {
		--this->_it;
		return *this;
	}
	Iterator& operator--(int) {
		--this->_it;
		return *this;
	}
	Iterator& operator+=(int n) {
		this->_it += n;
		return *this;
	}
	Iterator& operator-=(int n) {
		this->_it -= n;
		return *this;
	}
	Iterator operator+(int n) {
		return Iterator(this->_it + n, this->_end);
	}
	Iterator operator-(int n) {
		return Iterator(this->_it - n, this->_end);
	}
	// int operator-(const Iterator& rhs) {
	// 	return this->_it - rhs._it;
	// }
	// int operator+(const Iterator& rhs) {
	// 	return this->_it + rhs._it;
	// }
};
} // namespace ft

#endif
