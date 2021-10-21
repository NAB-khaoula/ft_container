#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iterator>
#include <cstddef>
#include <vector>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <math.h>

namespace ft
{
	//******************is_integral/ enable_if******************
	template <bool, typename T = void>
		struct enable_if{};

	template <typename T>
		struct enable_if<true, T> {
	  		typedef T type;
		};
	template <typename T>
		struct is_integral{
			static const bool value = false;
		};

	template <>
		struct is_integral<bool>{
			static const bool value = true;
		};
template <>
		struct is_integral<char>{
			static const bool value = true;
		};
	template <>
		struct is_integral<char16_t>{
			static const bool value = true;
		};
	template <>
		struct is_integral<char32_t>{
			static const bool value = true;
		};
	template <>
		struct is_integral<wchar_t>{
			static const bool value = true;
		};
	template <>
		struct is_integral<signed char>{
			static const bool value = true;
		};
	template <>
		struct is_integral<short int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<long int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<long long int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned char>{
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned short int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned long int>{
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned long long int>{
			static const bool value = true;
		};
	
	//******************is_integral/ enable_if******************
	
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		//****************** member Type ******************************
		typedef	T														value_type;
		typedef	Alloc													allocator_type;
		typedef	typename allocator_type::reference						reference;
		typedef	typename allocator_type::const_reference				const_reference;
		typedef	typename allocator_type::pointer						pointer;
		typedef	typename allocator_type::const_pointer					const_pointer;
		typedef	customizedIterator<pointer>								iterator;
		typedef	customizedIterator<const_pointer>						const_iterator;
		typedef	reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef	reverse_iterator<iterator>								reverse_iterator;
		typedef	typename iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t 													size_type;
		//****************** member Type ******************************
		//******************constructor******************
		vector(const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_array = nullptr;
			_size = 0;
			_capacity = 0;
		}
		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_array = _allocator.allocate(n);
			_size = n;
			_capacity = n;
			for (size_type i = 0; i < n; i++)
				_array[i] = val;
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = 0)
		{
			int i = -1;
			difference_type	dist = last - first;
			_allocator = alloc;
			_size = dist;
			_capacity = dist;
			_array = _allocator.allocate(dist);
			while(first != last){
				_array[++i] = *first;
				first++;
			}
		}
		vector(const vector &x)
		{
			(*this) = x;
		}
		//******************constructor******************
		//******************assignment operator******************
		vector &operator=(const vector &x)
		{
			_array = x._array;
			_size = x._size;
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

		iterator end(){
			iterator it(_array + _size);
			return (it);
		}

		reverse_iterator rbegin(){
			reverse_iterator it(_array + _size);
			return (it);
		}

		reverse_iterator rend(){
			reverse_iterator it(_array);
			return (it);
		}
		//******************iterator******************
		//******************method of Capacity******************
		size_type capacity() const{
			return _capacity;
		}

		size_type size() const{
			return _size;
		}

		size_type max_size() const{
			return (_allocator.max_size());
		}
		
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				pointer newArray = _allocator.allocate(_capacity);
				for (int i = n; i < _size; i++)
					newArray[i] = _array[i];
				_allocator.destroy(_array);
				_array = newArray;
				_size = n;
			}
			else if (n <= _capacity)
			{
				for (int i = n; i < _size; i++)
					_array[i] = val;
				_size = n;
			}
			else
			{
				if (n < _capacity * 2)
					for (int i = _size; i < n; i++)
						this->push_back(val);
				else{
					pointer newArray = _allocator.allocate(n);
					for (int i = 0; i < _capacity; i++)
						newArray[i] = _array[i];
					for (int i = _capacity; i < n; i++)
						newArray[i] = val;
					delete [] _array;
					_capacity = n;
					_size = n;
					_array = newArray;
				}
			}
		}

		bool empty() const
		{
			return (_size == 0);
		}

		void reserve(size_type n){
			if (n > _capacity)
			{
				pointer newArray = _allocator.allocate(n);
				for (int i = 0; i < _size; i++)
					newArray[i] = _array[i];
				_capacity = n;
			}
		}

		//******************method of Capacity******************
		//******************Element access******************
		reference operator[] (size_type n){
			return(*(_array + n));
		}

		const_reference operator[] (size_type n) const{
			return(*(_array + n));
		}

		reference at (size_type n){
			if (n < 0 || n >= _size)
				throw std::out_of_range("vector");
			return(_array[n]);
		}

		const_reference at (size_type n) const{
			if (n < 0 || n >= _size)
				throw std::out_of_range("Vector");
			return(_array[n]);
		}

		reference front(){
			return (*this->begin());
		}

		const_reference front() const{
			return (*this->begin());
		}

		reference back(){
			return(*(this->end() - 1));
		}

		const_reference back() const{
			return(*(this->end() - 1));
		}

		//******************Element access******************
		//******************Modifiers******************
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = 0){
				difference_type dist = last - first;
				if(dist <= _capacity){
					for(int i = 0; i < dist; i++)
						_array[i] = *first++;
					_size = dist;					
				}
				else{
					pointer newArray = _allocator.allocate(dist);
					for(int i = 0; i < dist; i++)
						newArray[i] = *first++;
					_allocator.deallocate(_array, _capacity);
					_array = newArray;
					_size = dist;
					_capacity = dist;
				}
			}
		void assign (size_type n, const value_type& val){
			if (n <= _capacity){
				for(int i = 0; i < n; i++)
					_array[i] = val;
				_size = n;
			}
			else{
				pointer newArray = _allocator.allocate(n);
				for(int i = 0; i < n; i++)
					newArray[i] = val;
				_allocator.deallocate(_array, _capacity);
				_array = newArray;
				_size = n;
				_capacity = n;
			}
		}
		void push_back(const value_type& val)
		{
			if (_size < _capacity)
			{
				this->_array[_size] = val;
				_size++;
			}
			else
			{
				pointer	newArray;
				if (!_capacity){
					newArray = _allocator.allocate(1);
					_capacity = 1;
				}
				else
				{
					newArray = _allocator.allocate(_capacity * 2);
					for(size_type i = 0; i < _capacity; i++)
						newArray[i] = _array[i];
					_allocator.deallocate(_array, _capacity);
					_capacity = _capacity * 2;
				}
				newArray[_size] = val;
				_size++;
				_array = newArray;
			}
		}

		void pop_back(){
			_allocator.destroy(_array + _size);
			_size--;
		}
		
		iterator insert (iterator position, const value_type& val){
			if (_size < _capacity){
				
			}
			else{

			}
		}

		void clear(){
			_allocator.deallocate(_array, _size);
			_size = 0;
		}

		// iterator erase (iterator position){
		// 	pointer newArray = _allocator.allocate(_capacity);
		// 	int i = -1;
		// 	iterator it = this->begin() - 1;
		// 	while(++it != position)
		// 		newArray[++i] = *it;
		// 	while(++it != this->end())
		// 		newArray[i++] = *it;
		// 	_allocator.deallocate(_array, _capacity);
		// 	_array = newArray;
		// 	return(it(_array));
		// }

		// void assign( size_type count, const T& value ){
		// 	this->clear();
		// 	for(int i = 0; i < count; i++)
		// 		this->push_back(value);
		// 	// _capacity = count;
		// 	_allocator.destroy(_array + count);
		// }
		// //ANCHOR need to add another prototype (iterator);
		// template <class InputIterator>
  		// void assign (InputIterator first, InputIterator last){

		// }

		// iterator erase( iterator pos ){

		// }

		// iterator erase( iterator first, iterator last ){

		// }

		//******************Modifiers******************


	private: 
		T *_array;
		size_type _size;
		size_type _capacity;
		Alloc _allocator;
	};

}
#endif