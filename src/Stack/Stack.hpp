#ifndef STACK_HPP
#define STACK_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "../Vector/Vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
	protected:
		Container c;
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		typedef typename Container::value_type value_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;
		typedef typename Container::difference_type difference_type;
		typedef typename Container::pointer pointer;
		typedef typename Container::const_pointer const_pointer;

		stack() : c() {};
		stack(const stack& other) : c(other.c) {};
		stack& operator=(const stack& other) {
			c = other.c;
			return *this;
		};

		iterator begin() { return c.begin(); };
		iterator end() { return c.end(); };
		const_iterator begin() const { return c.begin(); };
		const_iterator end() const { return c.end(); };
		reverse_iterator rbegin() { return c.rbegin(); };
		reverse_iterator rend() { return c.rend(); };
		const_reverse_iterator rbegin() const { return c.rbegin(); };
		const_reverse_iterator rend() const { return c.rend(); };

		bool empty() const { return c.empty(); };
		size_type size() const { return c.size(); };
		size_type max_size() const { return c.max_size(); };
		reference top() { return c.back(); };
		const_reference top() const { return c.back(); };
		void push(const T& value) { c.push_back(value); };
		void pop() { c.pop_back(); };

		bool operator==(const stack<T,Container>& lhs) const { return c == lhs.c; };
		bool operator!=(const stack<T,Container>& lhs) const { return c != lhs.c; };
		bool operator<(const stack<T,Container>& lhs) const { return c < lhs.c; };
		bool operator<=(const stack<T,Container>& lhs) const { return c <= lhs.c; };
		bool operator>(const stack<T,Container>& lhs) const { return c > lhs.c; };
		bool operator>=(const stack<T,Container>& lhs) const { return c >= lhs.c; };
};
}  // namespace ft
#endif
