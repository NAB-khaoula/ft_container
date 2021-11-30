#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include "__treeBeta.hpp"
#include "_tree_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft{

	template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<pair<const Key,T> > >
	class map{
		public:
		typedef Key																key_type;
		typedef T																mapped_type;
		typedef pair<const key_type, mapped_type> 								value_type;
		typedef Compare															key_compare;
		typedef Alloc															allocator_type;
		typedef value_type&						 								reference;
		typedef const value_type&												const_reference;
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
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef _tree_iterator<value_type, binaryTreeNode<value_type> >			iterator;
		typedef _tree_iterator<const value_type, binaryTreeNode<value_type> >	const_iterator;
		typedef reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef reverse_iterator<iterator>										reverse_iterator;
		typedef typename allocator_type::size_type								size_type;
		typedef typename allocator_type::difference_type						difference_type;
		typedef binarySearchTree<value_type, key_compare>						binarySearchTree;
		// NOTE constructors
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(){}
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			while(first != last)
			{
				_tree.insert(first->_data);
				first++;
			}
		}
		
		map (const map& x){
			(*this) = x;
		}

		map& operator=(const map& x)
		{
			_tree._root = x._tree._root;
			_tree._compare = x._tree._compare;
			_tree._allocator = x._tree._compare;
		}
		//FIXME need to destroy the object in my destructor;
		~map(){}

		//NOTE iterator function
		// iterator begin(){
		// 	return (iterator (_tree.get_min()));
		// }

		// const_iterator begin() const{
		// 	return (const_iterator (_tree.get_min()));
		// }

		// iterator end(){
		// 	// iterator it(_tree.get_max());
		// 	// it++;
		// 	// return (it);
		// 	return (iterator _root->parent);
		// }

		// const_iterator end() const{
		// 	// const_iterator it(_root->parent);
		// 	return (const_iterator _root->parent);
		// }

		// reverse_iterator rbegin(){
		// 	return (reverse_iterator (end()));
		// }

		// const_reverse_iterator rbegin() const{
		// 	return (const_reverse_iterator (end()));
		// }

		// reverse_iterator rend(){
		// 	return (reverse_iterator (begin()));
		// }

		// const_reverse_iterator rend() const{
		// 	return (const_reverse_iterator (begin()));
		// }

			binarySearchTree _tree;
		protected:
	};
		
}
#endif