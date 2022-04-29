#ifndef UTILS_HPP
#define UTILS_HPP

#include <sys/types.h>

namespace ft {

// SECTION equal
template <class InputIterator1, class InputIterator2>
class equality {
   public:
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
};
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
class predicate {
   public:
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
};
// !SECTION equal

// SECTION is_integral
template <typename T>
struct is_integral { static const bool value = false; };

template <>
struct is_integral<bool> { static const bool value = true; };

template <>
struct is_integral<char> { static const bool value = true; };

template <>
struct is_integral<char16_t> { static const bool value = true; };

template <>
struct is_integral<char32_t> { static const bool value = true; };

template <>
struct is_integral<wchar_t> { static const bool value = true; };

template <>
struct is_integral<signed char> { static const bool value = true; };

template <>
struct is_integral<short int> { static const bool value = true; };

template <>
struct is_integral<int> { static const bool value = true; };

template <>
struct is_integral<long int> { static const bool value = true; };

template <>
struct is_integral<long long int> { static const bool value = true; };

template <>
struct is_integral<unsigned char> { static const bool value = true; };

template <>
struct is_integral<unsigned short int> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<unsigned long int> { static const bool value = true; };

template <>
struct is_integral<unsigned long long int> { static const bool value = true; };
// !SECTION is_integral

// SECTION enable_if
template <bool Cond, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> { typedef T type; };
// !SECTION enable_if

// SECTION iterator_traits

// !SECTION

}  // namespace ft

#endif
