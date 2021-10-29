#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iterator>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"
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
			_allocator = x._allocator;
			pointer newArray = _allocator.allocate(x._capacity);
			for(size_type i = 0; i < x.size(); i++){
				newArray[i] = x._array[i];
			}
			_array = newArray;
			_size = x._size;
			_capacity = x._capacity;
		}
		//******************constructor******************
		//******************assignment operator******************
		vector &operator=(const vector &x)
		{
			_allocator.deallocate(_array, _capacity);
			_allocator = x._allocator;
			pointer newArray = _allocator.allocate(x._capacity);
			for(size_type i = 0; i < x.size(); i++){
				newArray[i] = x._array[i];
			}
			_array = newArray;
			_size = x._size;
			_capacity = x._capacity;
			return(*this);
		}
		//******************assignment operator******************
		//******************destructor******************
		~vector()
		{
			delete [] _array;
		}
		//******************destructor******************
		//******************iterator******************
		iterator begin(){
			return (iterator (_array));
		}

		const_iterator begin() const{
			return (const_iterator (_array));
		}

		iterator end(){
			return (iterator (_array + _size));
		}

		const_iterator end() const{
			return (const_iterator (_array + _size));
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
			return (std::min<size_type>(std::numeric_limits<difference_type>::max(), _allocator.max_size()));
		}
		
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				pointer newArray = _allocator.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					newArray[i] = _array[i];
				_allocator.deallocate(_array, _capacity);
				_array = newArray;
				_size = n;
			}
			else if (n <= _capacity)
			{
				for (size_type i = _size; i < n; i++)
					_array[i] = val;
				_size = n;
			}
			else
			{
				if (n < _capacity * 2)
					for (size_type i = _size; i < n; i++)
						this->push_back(val);
				else{
					pointer newArray = _allocator.allocate(n);
					for (size_type i = 0; i < _capacity; i++)
						newArray[i] = _array[i];
					for (size_type i = _capacity; i < n; i++)
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
				for (size_type i = 0; i < _size; i++)
					newArray[i] = _array[i];
				_allocator.deallocate(_array, _capacity);
				_array = newArray;
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
				if(dist <= (difference_type)_capacity){
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
				for(size_type i = 0; i < n; i++)
					_array[i] = val;
				_size = n;
			}
			else{
				pointer newArray = _allocator.allocate(n);
				for(size_type i = 0; i < n; i++)
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
			if(_size){
				_allocator.destroy(_array + _size);
				_size--;
			}
		}
		
		iterator insert (iterator position, const value_type& val){
			if (_size <= _capacity){
				iterator temporaryIterator = this->end() + 1;
				while(--temporaryIterator != position)
					*temporaryIterator = *(temporaryIterator - 1);
				*(position) = val; 
				_size++;
				return position;
			}
			else{
				pointer newArray = _allocator.allocate(_capacity * 2);
				int j = -1;
				for(iterator i = this->begin(); i < position; i++)
					newArray[++j] = *i;
				newArray[++j] = val;
				int k = j;
				for(iterator i = position; i < this->end(); i++)
					newArray[++j] = *i;
				_allocator.deallocate(_array, _capacity);
				_capacity *= 2;
				_size++;
				_array = newArray;
				return newArray + k;
			}
		}

		void insert (iterator position, size_type n, const value_type& val){
			if(_size + n < _capacity)
			{
				iterator temporaryIterator = this->end() + n;
				while(--temporaryIterator != position)
					*temporaryIterator = *(temporaryIterator - n);
				for(size_type i = 0; i < n; i++)
					*(position + i) = val; 
				_size += n;
			}
			else{
				size_type tempCapacity = _capacity;
				while(_size + n > _capacity * 2)
					_capacity *= 2;
				pointer newArray = _allocator.allocate(_capacity * 2);
				int j = -1;
				for(iterator i = this->begin(); i < position; i++)
					newArray[++j] = *i;
				for(size_type l = 0; l < n; l++)
					newArray[++j] = val;
				for(iterator i = position; i < this->end(); i++)
					newArray[++j] = *i;
				_allocator.deallocate(_array, tempCapacity);
				_capacity *= 2;
				_size += n;
				_array = newArray;
			}
		}

		template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = 0)
			{
				difference_type iteration = last - first;
				if(_size + iteration < _capacity)
				{
					iterator temporaryIterator = this->end() + iteration;
					while(--temporaryIterator != position)
						*temporaryIterator = *(temporaryIterator - iteration);
					for(int i = 0; i < iteration; i++)
						*(position + i) = *(first + i); 
					_size += iteration;
				}
				else{
					size_type tempCapacity = _capacity;
					while(_size + iteration > _capacity * 2)
						_capacity *= 2;
					pointer newArray = _allocator.allocate(_capacity * 2);
					int j = -1;
					for(iterator i = this->begin(); i < position; i++)
						newArray[++j] = *i;
					for(int l = 0; l < iteration; l++)
						newArray[++j] = *(first + l);
					for(iterator i = position; i < this->end(); i++)
						newArray[++j] = *i;
					_allocator.deallocate(_array, tempCapacity);
					_capacity *= 2;
					_size += iteration;
					_array = newArray;
				}
			}

		iterator erase (iterator position)
		{
			pointer newArray = _allocator.allocate(_capacity);
			int i = -1;
			iterator it = this->begin() - 1;
			while(++it < position)
				newArray[++i] = *it;
			while(++it != this->end())
				newArray[++i] = *it;
			_allocator.deallocate(_array, _capacity);
			_array = newArray;
			_size--;
			return(position + 1);
		}

		iterator erase (iterator first, iterator last){
			pointer newArray = _allocator.allocate(_capacity);
			int i = -1;
			iterator it = this->begin() - 1;
			while(++it != first)
				newArray[++i] = *it;
			it = last - 1;
			while(++it != this->end())
				newArray[++i] = *it;
			_allocator.deallocate(_array, _capacity);
			_array = newArray;
			_size -= (size_type)(last - first);
			return (last);
		}
		void clear(){
			while(_size)
			{
				_allocator.destroy(_array + _size);
				_size--;
			}
		}

		void swap (vector& x){
			vector temporary = x;
			x = *this;
			*this = temporary;
		}
		//******************Modifiers******************
		
		//******************Allocator******************
		allocator_type get_allocator() const{
			return (_allocator);
		}
		//******************Allocator******************

		template <class Ta, class Alloca>
			friend bool operator== (const vector<Ta,Alloca>& lhs, const vector<Ta,Alloca>& rhs)
			{
				return(equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

		template <class Ta, class Alloca>
			friend bool operator!= (const vector<Ta,Alloca>& lhs, const vector<Ta,Alloca>& rhs)
			{
				return(!(lhs == rhs));
			}

		template <class Ta, class Alloca>
			friend bool operator<  (const vector<Ta,Alloca>& lhs, const vector<Ta,Alloca>& rhs)
			{
				return(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
		
		template <class Ta, class Alloca>
			friend bool operator<= (const vector<Ta,Alloca>& lhs, const vector<Ta,Alloca>& rhs)
			{
				return(!(rhs < lhs));
			}

		template <class Ta, class Alloca>
			friend bool operator>  (const vector<Ta,Alloca>& lhs, const vector<Ta,Alloca>& rhs)
			{
				return(rhs < lhs);
			}

		template <class Ta, class Alloca>
			friend bool operator>= (const vector<Ta,Alloca>& lhs, const vector<Ta,Alloca>& rhs)
			{
				return(!(lhs < rhs));
			}



	private: 
		T *_array;
		size_type _size;
		size_type _capacity;
		Alloc _allocator;
	};
}
#endif