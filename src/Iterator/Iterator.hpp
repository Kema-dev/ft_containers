#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft {
template <class Category,			   // iterator::iterator_category
		  class T,					   // iterator::value_type
		  class Distance = ptrdiff_t,  // iterator::difference_type
		  class Pointer = T*,		   // iterator::pointer
		  class Reference = T&		   // iterator::reference
		  >
class Iterator {
   public:
	Category iterator_category;
	T value_type;
	ptrdiff_t difference_type;
	T* pointer;
	T& reference;


};
}  // namespace ft

#endif