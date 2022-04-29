#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>


namespace ft {
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator {
   public:
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer_it;
	typedef Reference reference;
};

template <class T>
class iterator_traits {
	public:
		typedef typename T::iterator::difference_type difference_type;
		typedef typename T::iterator::value_type value_type;
		typedef typename T::iterator::pointer_it pointer;
		typedef typename T::iterator::reference reference;
		typedef typename T::iterator::iterator_category iterator_category;
};

}  // namespace ft

#endif
