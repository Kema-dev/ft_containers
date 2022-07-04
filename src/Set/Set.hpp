#ifndef SET_HPP
#define SET_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"

namespace ft {

template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set {
	private:
		ft::map<T,T,Compare,Alloc> _container;
	public:
		typedef T key_type;
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef Alloc allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;

		// set( void ) : _container( void ) {};
        explicit set (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _container(comp, alloc) {};
		set(const set& other) : _container(other._container) {};
		template<class InputIterator>
		set(InputIterator first, InputIterator last) : _container(first, last) {};
		set& operator=(const set& other) {
			_container = other._container;
			return *this;
		};

		class iterator : public ft::map<T,T,Compare,Alloc>::iterator {
			public:
				iterator() : ft::map<T,T,Compare,Alloc>::iterator() {};
				iterator(const typename ft::map<T,T,Compare,Alloc>::iterator& other) : ft::map<T,T,Compare,Alloc>::iterator(other) {};
				iterator(const iterator& other) : ft::map<T,T,Compare,Alloc>::iterator(other) {};
				iterator& operator=(const iterator& other) {
					ft::map<T,T,Compare,Alloc>::iterator::operator=(other);
					return *this;
				};
				iterator& operator++() {
					ft::map<T,T,Compare,Alloc>::iterator::operator++();
					return *this;
				};
				iterator operator++(int) {
					iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::iterator::operator++();
					return tmp;
				};
				iterator& operator--() {
					ft::map<T,T,Compare,Alloc>::iterator::operator--();
					return *this;
				};
				iterator operator--(int) {
					iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::iterator::operator--();
					return tmp;
				};
				const T& operator*() {
					return ft::map<T,T,Compare,Alloc>::iterator::operator*().first;
				};
		};

		class const_iterator : public ft::map<T,T,Compare,Alloc>::const_iterator {
			public:
				const_iterator() : ft::map<T,T,Compare,Alloc>::const_iterator() {};
				const_iterator(const typename ft::map<T,T,Compare,Alloc>::const_iterator& other) : ft::map<T,T,Compare,Alloc>::const_iterator(other) {};
				const_iterator(const const_iterator& other) : ft::map<T,T,Compare,Alloc>::const_iterator(other) {};
				const_iterator& operator=(const const_iterator& other) {
					ft::map<T,T,Compare,Alloc>::const_iterator::operator=(other);
					return *this;
				};
				const_iterator& operator++() {
					ft::map<T,T,Compare,Alloc>::const_iterator::operator++();
					return *this;
				};
				const_iterator operator++(int) {
					const_iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::const_iterator::operator++();
					return tmp;
				};
				const_iterator& operator--() {
					ft::map<T,T,Compare,Alloc>::const_iterator::operator--();
					return *this;
				};
				const_iterator operator--(int) {
					const_iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::const_iterator::operator--();
					return tmp;
				};
				const T& operator*() {
					return ft::map<T,T,Compare,Alloc>::const_iterator::operator*().first;
				};
		};

		class reverse_iterator : public ft::map<T,T,Compare,Alloc>::reverse_iterator {
			public:
				reverse_iterator() : ft::map<T,T,Compare,Alloc>::reverse_iterator() {};
				reverse_iterator(const typename ft::map<T,T,Compare,Alloc>::reverse_iterator& other) : ft::map<T,T,Compare,Alloc>::reverse_iterator(other) {};
				reverse_iterator(const reverse_iterator& other) : ft::map<T,T,Compare,Alloc>::reverse_iterator(other) {};
				reverse_iterator& operator=(const reverse_iterator& other) {
					ft::map<T,T,Compare,Alloc>::reverse_iterator::operator=(other);
					return *this;
				};
				reverse_iterator& operator++() {
					ft::map<T,T,Compare,Alloc>::reverse_iterator::operator++();
					return *this;
				};
				reverse_iterator operator++(int) {
					reverse_iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::reverse_iterator::operator++();
					return tmp;
				};
				reverse_iterator& operator--() {
					ft::map<T,T,Compare,Alloc>::reverse_iterator::operator--();
					return *this;
				};
				reverse_iterator operator--(int) {
					reverse_iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::reverse_iterator::operator--();
					return tmp;
				};
				const T& operator*() {
					return ft::map<T,T,Compare,Alloc>::reverse_iterator::operator*().first;
				};
		};

		class const_reverse_iterator : public ft::map<T,T,Compare,Alloc>::const_reverse_iterator {
			public:
				const_reverse_iterator() : ft::map<T,T,Compare,Alloc>::const_reverse_iterator() {};
				const_reverse_iterator(const typename ft::map<T,T,Compare,Alloc>::const_reverse_iterator& other) : ft::map<T,T,Compare,Alloc>::const_reverse_iterator(other) {};
				const_reverse_iterator(const const_reverse_iterator& other) : ft::map<T,T,Compare,Alloc>::const_reverse_iterator(other) {};
				const_reverse_iterator& operator=(const const_reverse_iterator& other) {
					ft::map<T,T,Compare,Alloc>::const_reverse_iterator::operator=(other);
					return *this;
				};
				const_reverse_iterator& operator++() {
					ft::map<T,T,Compare,Alloc>::const_reverse_iterator::operator++();
					return *this;
				};
				const_reverse_iterator operator++(int) {
					const_reverse_iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::const_reverse_iterator::operator++();
					return tmp;
				};
				const_reverse_iterator& operator--() {
					ft::map<T,T,Compare,Alloc>::const_reverse_iterator::operator--();
					return *this;
				};
				const_reverse_iterator operator--(int) {
					const_reverse_iterator tmp(*this);
					ft::map<T,T,Compare,Alloc>::const_reverse_iterator::operator--();
					return tmp;
				};
				const T& operator*() {
					return ft::map<T,T,Compare,Alloc>::const_reverse_iterator::operator*().first;
				};
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
		// ft::pair<iterator, bool> insert(const T& val) {
		// 	ft::pair<typename ft::map<T,T,Compare,Alloc>::iterator, bool> buf = _container.insert(make_pair(val, val));
		// 	return ft::pair<iterator, bool>(iterator(buf.first), buf.second);
		// };
		iterator insert(iterator position, const value_type& val) {
			static_cast<void>(position);
			_container.insert(make_pair(val, val));
			return iterator(_container.find(val));
		};
        ft::pair<iterator,bool> insert (const value_type& val) {
			_container.insert(ft::pair<const T, T>(val, val));
			return ft::pair<iterator,bool>(iterator(_container.find(val)), true);
		};
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last) { _container.insert(first, last); };
		void erase(iterator it) { _container.erase(it); };
		void erase(iterator first, iterator last) { _container.erase(first, last); };
		size_type erase(const T& value) { return _container.erase(value); };
		void swap(set& other) { _container.swap(other._container); };
		void clear() { _container.clear(); };
		key_compare key_comp() const { return _container.key_comp(); };
		value_compare value_comp() const { return Compare(); };

		iterator find(const T& value) { return _container.find(value); };
		const_iterator find(const T& value) const { return _container.find(value); };
		size_type count(const T& value) const { return _container.count(value); };
		iterator lower_bound(const T& value) { return _container.lower_bound(value); };
		const_iterator lower_bound(const T& value) const { return _container.lower_bound(value); };
		iterator upper_bound(const T& value) { return _container.upper_bound(value); };
		const_iterator upper_bound(const T& value) const { return _container.upper_bound(value); };
		// ft::pair<iterator, iterator> equal_range(const T& value) { return _container.equal_range(value); };
		ft::pair<iterator, iterator> equal_range(const T& value) {
			ft::pair<typename ft::map<T,T,Compare,Alloc>::iterator, typename ft::map<T,T,Compare,Alloc>::iterator> buf = _container.equal_range(value);
			return ft::pair<iterator, iterator>(iterator(buf.first), iterator(buf.second));
		};
		// ft::pair<const_iterator, const_iterator> equal_range(const T& value) const { return _container.equal_range(value); };
		ft::pair<const_iterator, const_iterator> equal_range(const T& value) const {
			ft::pair<typename ft::map<T,T,Compare,Alloc>::const_iterator, typename ft::map<T,T,Compare,Alloc>::const_iterator> buf = _container.equal_range(value);
			return ft::pair<const_iterator, const_iterator>(const_iterator(buf.first), const_iterator(buf.second));
		};
		allocator_type get_allocator() const { return _container.get_allocator(); };
		void print(void) { _container.print(); };
};
}  // namespace ft
#endif
