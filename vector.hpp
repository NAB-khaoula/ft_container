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

		iterator end(){
			iterator it(_array + _current);
			return (it);
		}
		
		// reverse_iterator rbegin(){
		// 	reverse_iterator it(_array.end());
		// 	return (it);
		// }

		// iterator end(){
		// 	iterator it(_array);
		// 	return (it);
		// }
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
		size_type _current;
		size_type _capacity;
		Alloc _allocator;
	};

}
#endif