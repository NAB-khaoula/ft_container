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
	struct binaryTreeNode{
		T data;
		binaryTreeNode *left;
		binaryTreeNode *right;
	};

	template <class T, class Alloc>
	class bst{
		binaryTreeNode<T> *root;
		public:
		bst(){
			root=NULL;
		}
		int isempty(){
			return(root==NULL);
		}
		void insert(T item){
			binaryTreeNode *p = new binaryTreeNode;
			binaryTreeNode *parent;
			p->data = item;
			p->left = NULL;
			p->right = NULL;
			parent = NULL;
			if(isempty())
				root=p;
			else{
				binaryTreeNode *ptr;
				ptr=root;
				while(ptr!=NULL)
				{
					parent=ptr;
					if(item > ptr->data)
						ptr = ptr->right;
					else
						ptr=ptr->left;
				}
				if(item < parent->data)
					parent->left=p;
				else
					parent->right=p;
			}
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
		// typedef	class map<Key,T,Compare,Alloc>::value_compare
		// {
		// 	friend class map;
		// protected:
		// 	Compare comp;
		// 	value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		// public:
		// 	typedef bool result_type;
		// 	typedef value_type first_argument_type;
		// 	typedef value_type second_argument_type;
		// 	bool operator() (const value_type& x, const value_type& y) const
		// 	{
		// 	  return comp(x.first, y.first);
		// 	}
		// }													value_compare;
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