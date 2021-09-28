#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

template <typename T, typename Alloc = std::allocator<T> >
class ft_vector
{
	private:
		T*	_array;
		int	_current;
		int _capacity;
	public:
		//****************** member Type ******************************
		typedef	T					value_type;
		typedef	Alloc<value_type>	allocator_type;
		allocator_type		&reference;
		const allocator_type	&const_reference;
		allocator_type		*pointer;
		const allocator_type	*const_pointer;
		std::random_access_iterator_tag	iterator;
		const std::random_access_iterator_tag	const_iterator;
		std::reverse_iterator<iterator>	reverse_iterator;
		std::reverse_iterator<const_iterator> const_reverse_iterator;
		std::iterator_traits<iterator>	difference_type;
		typedef	size_t		size_type;
		//****************** member Type ******************************
		ft_vector(const allocator_type& alloc = allocator_type()){
			_array = nullptr;
			_current = 0;
			_capacity = 0;
		}
		ft_vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
			_array = std::allocate(n);
			_current = 0;
			_capacity = n;
		}
		template <class InputIterator>
        ft_vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
			
		}
		ft_vector (const ft_vector& x){
			(*this) = x;
		}
		~ft_vector(){
			std::deallocate(_array);
		}
};

#endif