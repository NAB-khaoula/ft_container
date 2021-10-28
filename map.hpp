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
		pair() : first_type(), second_type(){}
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
			return(!(lhs == rhs)));
		}
	};

}
#endif