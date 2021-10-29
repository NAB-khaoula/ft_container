#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iterator>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft{

	template <class T1, class T2> 
	struct pair{
		typedef T1  first_type;
		typedef T2  second_type;
		first_type first;
		second_type second;
		pair():first(first_type()), second(second_type()){}
		pair (const first_type& a, const second_type& b): first(a), second(b){}
		template<class U, class V>
		pair (const pair<U,V>& pr){
			first = pr.first;
			second = pr.second;
		}
		pair& operator= (const pair& pr){
				first = pr.first;
				second = pr.second;
				return (*this);
		}
		template <class U, class V>
			friend bool operator== (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return(lhs.first == rhs.first && lhs.first == rhs.second);
			}
		
		template <class U, class V>
			friend bool operator!= (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return(!(lhs == rhs));
			}
		
		template <class U, class V>
			friend bool operator<  (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return (lhs.first<rhs.first && lhs.second<rhs.second); 
			}

		template <class U, class V>
			friend bool operator<= (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{ 
				return (!(rhs<lhs)); 
			}

		template <class U, class V>
			friend bool operator>  (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{ 
				return rhs<lhs;
			}

		template <class U, class V>
			friend bool operator>= (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return !(lhs<rhs);
			}
	};
	template <class T1,class T2>
  		pair<T1,T2> make_pair (T1 x, T2 y)
  		{
    		return ( pair<T1,T2>(x,y) );
  		}
	
	template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<pair<const Key,T> > >
	class map{
		
	};
}
#endif