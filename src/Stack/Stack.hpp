#ifndef STACK_HPP
#define STACK_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "../Vector/Vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
	private:
		Container _container;
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

		stack() : _container() {};
		stack(const stack& other) : _container(other._container) {};
		stack& operator=(const stack& other) {
			_container = other._container;
			return *this;
		};

		iterator begin() { return _container.begin(); };
		iterator end() { return _container.end(); };
		const_iterator begin() const { return _container.begin(); };
		const_iterator end() const { return _container.end(); };
		reverse_iterator rbegin() { return _container.rbegin(); };
		reverse_iterator rend() { return _container.rend(); };
		const_reverse_iterator rbegin() const { return _container.rbegin(); };
		const_reverse_iterator rend() const { return _container.rend(); };

		bool empty() const { return _container.empty(); };
		size_type size() const { return _container.size(); };
		size_type max_size() const { return _container.max_size(); };
		reference top() { return _container.back(); };
		const_reference top() const { return _container.back(); };
		void push(const T& value) { _container.push_back(value); };
		void pop() { _container.pop_back(); };

		bool operator==(const stack<T,Container>& lhs) const { return _container == lhs._container; };
		bool operator!=(const stack<T,Container>& lhs) const { return _container != lhs._container; };
		bool operator<(const stack<T,Container>& lhs) const { return _container < lhs._container; };
		bool operator<=(const stack<T,Container>& lhs) const { return _container <= lhs._container; };
		bool operator>(const stack<T,Container>& lhs) const { return _container > lhs._container; };
		bool operator>=(const stack<T,Container>& lhs) const { return _container >= lhs._container; };
};
}  // namespace ft
// !SECTION namespace ft
#endif
