#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iterator>
#include <cstddef>
#include <vector>
#include <math.h>

namespace ft
{
	template<typename Iterator>
	struct iterator_traits
	{
		typedef Iterator::difference_type		difference_type;
		typedef Iterator::value_type 			value_type;
		typedef Iterator::pointer				pointer;
		typedef Iterator::reference			reference;
		typedef Iterator::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	//****************** iterator struct***************************
	template <class Iterator>
	class custumozedIterator : public iterator<std::random_access_iterator_tag, iterator_traits<Iterator>::value_type >
	{
		typedef Iterator													iterator_type;
    	typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
    	typedef typename iterator_traits<iterator_type>::value_type			value_type;
    	typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
    	typedef typename iterator_traits<iterator_type>::pointer			pointer;
    	typedef typename iterator_traits<iterator_type>::reference			reference;
		public:

			//****************** constructors ***************************
			iterator(): _iter(nullptr){
			}

			iterator(pointer iter): _iter(iter){	
			}

			iterator(const iterator& iter){
				(*this) = iter;
			}

			iterator& operator=(const iterator& iter){
				this->_iter = iter._iter;
				return (*this);
			}
			//****************** constructors ***************************
			//****************** operators overload ***************************
			//****************** operators overload ***************************
			reference operator*() const{
				return(*_iter);
			}

			iterator& operator++(){
				this->_iter++;
				return (*this);
			}

			iterator  operator++(int){
				iterator post_increment = *this;
				this->_iter++;
				return (post_increment);
			}

			iterator operator+(difference_type n) const{
				return (this->_iter + n);
			}

			iterator &operator+=(difference_type n){
				this->_iter = this->_iter + n;
				return(*this);
			}

			iterator operator-(difference_type n) const{
				return (this->_iter - n);
			}

			iterator& operator--(){
				this->_iter--;
				return (*this);
			}

			iterator  operator--(int){
				iterator post_increment = *this;
				this->_iter--;
				return (post_increment);
			}

			iterator &operator-=(difference_type n){
				this->_iter = this->_iter - n;
				return(*this);
			}

			pointer operator->() const {
  				return &(operator*());
			}

			reference operator[] (difference_type n) const{
				return (this->_iter[n]);
			}

			friend iterator<Category, T> operator+ (typename iterator<Category, T>::difference_type n, const iterator<Category, T>& it){
				return (it._iter + n);
			}

			friend iterator<Category, T> operator- (typename iterator<Category, T>::difference_type n, const iterator<Category, T>& it){
				return (it._iter - n);
			}
			//****************** operators overload ***************************

		private:
			pointer _iter;
	};

	//****************** iterator struct***************************
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		//****************** member Type ******************************
		typedef	T							value_type;
		typedef	typename Alloc<value_type>	allocator_type;
		typedef	value_type&					reference;
		typedef	const value_type&			const_reference;
		typedef	value_type*					pointer;
		typedef	const value_type* 			const_pointer;
		typedef size_t size_type;
		typedef	iterator<std::random_access_iterator_tag, value_type> iterator;
		//****************** member Type ******************************
		//******************constructor******************
		vector(const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_array = nullptr;
			_current = 0;
			_capacity = 0;
		}
		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_array = _allocator.allocate(n);
			_current = n;
			_capacity = n;
			for (size_type i = 0; i < n; i++)
				_array[i] = val;
		}
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
		// 	int i = 0;
		// 	_allocator = alloc;
		// 	while (first != last)
		// 	{
		// 		i++;
		// 		first++;
		// 	}
		// 	_current = 0;
		// 	_capacity = i;
		// 	_array = _allocator.allocate(i);
		// }
		vector(const vector &x)
		{
			(*this) = x;
		}
		//******************constructor******************
		//******************assignment operator******************
		vector &operator=(const vector &x)
		{
			_array = x._array;
			_current = x._current;
			_capacity = x._capacity;
			_allocator = x._allocator;
		}
		//******************assignment operator******************
		//******************destructor******************
		~vector()
		{
			_allocator.deallocate(this->_array, _capacity);
		}
		//******************destructor******************
		//******************iterator******************
		iterator begin(){
			iterator it(_array);
			return (it);
		}
		//******************iterator******************
		//******************Modifiers******************
		void push_back(const value_type& val){
			if (_current < _capacity)
			{
				this->_array[_current] = val;
				_current++;
			}
			else
			{
				// std::cout << "allocating new memory" << std::endl;
				T*	_newArray;
				if (_capacity)
					_newArray = _allocator.allocate(_capacity * 2);
				else
					_newArray = _allocator.allocate(1);
				if (_capacity != 0){
					for(size_type i = 0; i < _capacity; i++)
						_newArray[i] = _array[i];
				}
				_newArray[_current] = val;
				_current++;
				_allocator.deallocate(_array, _capacity);
				if (_capacity)
					_capacity = _capacity * 2;
				else
					_capacity = 1;
				_array = _newArray;
			}
		}
		//******************Modifiers******************
		//******************method of Capacity******************
		// need verification!!
		size_type capacity() const
		{
			return _capacity;
		}
		size_type size() const
		{
			return _current;
		}
		size_type max_size() const
		{
			size_type maxSize = pow(2, 64) / sizeof(value_type);
			return (maxSize - 1);
		}
		bool empty() const
		{
		}
		//******************method of Capacity******************
	private:
		T *_array;
		int _current;
		size_type _capacity;
		Alloc _allocator;
	};

}
#endif