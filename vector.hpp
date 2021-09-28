#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	private:
		T*	_array;
		int	_current;
		int _capacity;
	public:
		//****************** member Type ******************************
		T					value_type;
		Alloc<valueType>	allocator_type;
		allocator_type		&reference;
		const allocator_type	&const_reference;
		allocator_type		*pointer;
		const allocator_type	*const_pointer;
		std::random_access_iterator_tag	iterator;
		const std::random_access_iterator_tag	const_iterator;
		std::reverse_iterator<iterator>	reverse_iterator;
		std::reverse_iterator<const_iterator> const_reverse_iterator;
		//****************** member Type ******************************
		vector();
		~vector();
};

#endif