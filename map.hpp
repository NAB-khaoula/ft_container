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

	template <class T>
	struct binaryTreeNode
	{
		T				_data;
		binaryTreeNode*	_left;
		binaryTreeNode*	_right;
	};

	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
	class binarySearchTree
	{
		binaryTreeNode<T>*	_root;
		Alloc				_allocator;
		Compare				_compare;
		public:
		binarySearchTree()
		{
			_root = NULL;
			_allocator = Alloc();
			_compare = Compare();
		}
		int isempty()
		{
			return(_root == NULL);
		}
		void insert(T item){
			binaryTreeNode<T> *p = _allocator.allocate(1);
			binaryTreeNode<T> *parent;
			p->_data = item;
			p->_left = NULL;
			p->_right = NULL;
			parent = NULL;
			if(isempty())
				_root = p;
			else
			{
				binaryTreeNode<T> *ptr;
				ptr = _root;
				while(ptr != NULL)
				{
					parent = ptr;
					if(_compare(item.first, parent->_data.first))
						ptr = ptr->_left;
					else if (item.first == parent->_data.first)
						break;
					else
						ptr = ptr->_right;
				}
				if (_compare(item.first, parent->_data.first))
					parent->_left = p;
				else if (item == parent->_data)
					parent->_data = item;
				else
					parent->_right = p;
			}
		}
		void	printNode(binaryTreeNode<T> *child)
		{
			if(child->_left != NULL)
				printNode(child->_left);
			std::cout << child->_data.first << ":" << child->_data.second << std::endl;
			if (child->_right != NULL)
				printNode(child->_right);
		}

		void	printTree()
		{
			if(_root != NULL)
				printNode(_root);
			else
				std::cout << "empty tree!" << std::endl;
		}
	};

	template < class Key, class T, class Compare = std::less<Key>,class Alloc = std::allocator<pair<const Key,T> > >
	class map{
		// protected:
		
		public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<const key_type, const mapped_type> 	value_type;
		typedef Compare										key_compare;
		typedef	class map<Key,T,Compare,Alloc>::value_compare : public binary_function<value_type, value_type, bool>
		{
				friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				result_type operator() (const first_argument_type& x, const second_argument_type& y) const
				{
				  return comp(x.first, y.first);
				}
		}													value_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
	};
}
#endif