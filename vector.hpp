#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <math.h>

namespace ft{
template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	public:
		//****************** member Type ******************************
		typedef	T					value_type;
		typedef	Alloc				allocator_type;
		// allocator_type		&reference;
		// const allocator_type	&const_reference;
		// allocator_type		*pointer;
		// const allocator_type	*const_pointer;
		typedef std::random_access_iterator_tag	iterator(value_type);
		// const std::random_access_iterator_tag	const_iterator;
		// std::reverse_iterator<iterator>	reverse_iterator;
		// std::reverse_iterator<const_iterator> const_reverse_iterator;
		// std::iterator_traits<iterator>	difference_type;
		typedef	size_t		size_type;
		//****************** member Type ******************************
		//******************constructor******************
		vector(const allocator_type& alloc = allocator_type()){
			_allocator = alloc;
			_array = nullptr;
			_current = 0;
			_capacity = 0;
		}
		vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
			_allocator = alloc;
			_array = _allocator.allocate(n);
			_current = 0;
			_capacity = n;
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
		vector (const vector& x){
			(*this) = x;
		}
		//******************constructor******************
		//******************assignment operator******************
		vector& operator= (const vector& x){
			_array = x._array;
			_current = x._current;
			_capacity = x._capacity;
			_allocator = x._allocator;
		}
		//******************assignment operator******************
		//******************destructor******************
		~vector(){
			_allocator.deallocate(_array, _capacity);
		}
		//******************destructor******************
		//******************method of Capacity******************
		// need verification!!
		size_type capacity() const{
			if (!_current)
				return _capacity;
			else
				return _current;
		}
		size_type size() const{
			return _capacity;
		}
		size_type max_size() const{
			size_type maxSize = pow(2,64)/sizeof(value_type);
			return (maxSize - 1);
		}
		bool empty() const{
			
		}
		//******************method of Capacity******************
	private:
		T*			_array;
		int			_current;
		size_type 	_capacity;
		Alloc		_allocator;
};

}
#endif