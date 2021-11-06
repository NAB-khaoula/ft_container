#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include "__tree.hpp"
#include "_tree_iterator.hpp"
// #include "reverse_iterator.hpp"

namespace ft{

	template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<pair<const Key,T> > >
	class map{
		public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef pair<const key_type, mapped_type> 				value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef value_type&						 				reference;
		typedef const value_type&								const_reference;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
				friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c){}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				result_type operator() (const first_argument_type& x, const second_argument_type& y) const
				{
				  return comp(x.first, y.first);
				}
		};
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		typedef binarySearchTree<value_type, key_compare>		binarySearchTree;
		typedef _tree_iterator<value_type, binaryTreeNode<T> >	_tree_iterator;
		// NOTE constructors
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){}
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){}
		
		map (const map& x){}
		protected:
			binarySearchTree _tree;
	};
}
#endif