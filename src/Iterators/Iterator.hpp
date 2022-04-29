#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>


namespace ft {
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator {
   public:
	Category iterator_category;
	T value_type;
	Distance difference_type;
	Pointer pointer;
	Reference reference;
};

template <class T>
class iterator_traits {
	public:
		typedef T::iterator::difference_type difference_type;
		typedef T::iterator::value_type value_type;
		typedef T::iterator::pointer pointer;
		typedef T::iterator::reference reference;
		typedef T::iterator::iterator_category iterator_category;
};

}  // namespace ft

#endif
