
#ifndef FT_CONTAINERS_VECTOR_HPP
# define FT_CONTAINERS_VECTOR_HPP
# include <iostream>
# include <cmath>
# include "../Iterators/Iterator.hpp"
# include "../Iterators/ReverseIterator.hpp"

# define EXPANDING_RATIO 2

namespace ft {
	class OutOfRangeException : public std::exception {
	public:
		const char *what () const throw ()
		{
			return "Request is out of bounds";
		}
	};
	template<typename T, class alloc = std::allocator<T> >
	class vector {
	public:
		// typedef random_access_iterator 			const_iterator;
		// typedef reverse_iterator<random_access_iterator> const_reverse_iterator;
		// typedef typename alloc::const_reference	const_reference;
		// typedef typename alloc::const_pointer	const_pointer;
		typedef T								value_type;
		typedef alloc							allocator_type;
		typedef typename alloc::reference		reference;
		typedef typename alloc::pointer			pointer;
		typedef Iterator						iterator;
		typedef ReverseIterator					reverse_iterator;
		typedef std::ptrdiff_t					difference_type;
		typedef size_t							size_type;
	protected:
		alloc						_alloc;
		T*							_array;
		size_type					_size;
		size_type					_capacity;

		public:
			//	*	Constructors
			vector(void) {
			};
			explicit vector(const allocator_type &alloct = allocator_type())
				: _capacity(2), _size(0), _alloc(alloct) {
				_array = _alloc.allocate(sizeof(T) * _capacity);
			};
			vector(const vector& other) {
				*this = other;
			};
			explicit vector(size_type n,
							const value_type &val = value_type(),
							const allocator_type &alloct = allocator_type())
							: _alloc(alloct), _capacity(n), _size(n) {
				if (_capacity != 0)
					_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size ; i++) {
					_alloc.construct(&_array[i], val);
				}
			};
			template <class InputIterator>
			vector (InputIterator first,
					InputIterator last,
					const allocator_type& alloct = allocator_type())
					: _alloc(alloct), _capacity(0), _size(0) {
				for (InputIterator it = first; it < last; it++) {
					_size++;
				}
				_capacity = capacity(_size);
				if (_capacity != 0)
					_array = _alloc.allocate(_capacity);
				size_t i = 0;
				for (InputIterator it = first; it != last ; it++) {
					_alloc.construct(&_array[i++], *it);
				}
			}
			//	*	Destructor
			virtual ~vector() {
				clear();
			};
			//	*	Other member functions
			vector &operator=(vector const &rhs) {
				if (this != rhs)
				{
					clear();
					_alloc = rhs._alloc;
					_capacity = rhs._capacity;
					if (_capacity != 0)
						_array = _alloc.allocate(_capacity);
					insert(this->begin(), rhs.begin(), rhs.end());
				}
				return (*this);
			};
			allocator_type get_allocator() const {
				return allocator_type();
			}
			//	*	Element access
			reference at(size_type n) {
				if (n >= _size)
					throw OutOfRangeException();
				return (_array[n]);
			}
			reference	operator[](size_type n) {
				if (n >= _size)
					throw OutOfRangeException();
				return (_array[n]);
			}
			reference front() {
				return (_array[0]);
			}
			reference back() {
				return (_array[_size]);
			}
			T* data() {
				return (_array); // ! Not sure of that
			}
			//	*	Iterators
			iterator	begin(void) {
				return &_array[0];
			}
			iterator	end(void) {
				return &_array[_size];
			}
			reverse_iterator	rbegin(void) {
				return reinterpret_cast<reverse_iterator>(end());
			}
			reverse_iterator	rend(void) {
				return reinterpret_cast<reverse_iterator>(begin());
			}
			//	*	Capacity
			bool empty(void) const {
				return _size == 0 ? true : false;
			}
			size_t	size(void) {
				return _size;
			}
			size_t	max_size(void) {
				return _alloc.max_size() / sizeof(T);
			}
			void reserve (size_type n) {
				if (n > _capacity) {
					_capacity = n;
					pointer buf = _alloc.allocate(sizeof(T) * _capacity);
					for (_size = 0; _size < _capacity; _size++) {
						_alloc.construct(&buf[_size], _array[_size]);
						_alloc.destroy(&_array[_size]);
					}
					_alloc.deallocate(_array, _capacity);
					_array = buf;
				}
			}
			size_t	capacity(void) {
				return _capacity;
			}
			//	*	Modifiers
			void clear() {
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_array[i]);
				if (_capacity > 0)
					_alloc.deallocate(_array, _capacity);
				_size = 0;
				_capacity = 0;
			}
			void resize (size_type n,
						value_type val = value_type()) {
				if (n <= _size) {
					for (_size = 0; _size < _capacity && _size < n; _size++) {
						_alloc.construct(&_array[_size], val);
					}
					for (size_type i = _size; i < n; i++) {
						_alloc.destroy(&_array[i]);
					}
				}
				else {
					clear();
					_capacity = EXPANDING_RATIO * n;
					_array = _alloc.allocate(sizeof(T) * _capacity);
					for (_size = 0; _size < _capacity; _size++) {
						_alloc.construct(&_array[_size], val);
					}
				}
			}
			
	};

}

#endif