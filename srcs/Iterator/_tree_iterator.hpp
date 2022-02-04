#ifndef _TREE_ITERATOR_HPP
#define _TREE_ITERATOR_HPP
#include <iostream>
#include <cstddef>
#include "../Tree/__tree.hpp"


namespace ft{

	//******************iterator_traits that convert normal pointer***************************
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template<typename Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type 			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
		};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::bidirectional_iterator_tag		iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::bidirectional_iterator_tag		iterator_category;
	};
	//******************iterator_traits that convert normal pointer/ const pointer***************************

	template<class T, class _node>
	class _tree_iterator : public iterator<std::bidirectional_iterator_tag, typename iterator_traits<T *>::value_type >
	{
		public:
			typedef	_node*												_treePointerNode;
			typedef typename iterator_traits<T *>::iterator_category	iterator_category;
			typedef typename iterator_traits<T *>::value_type		value_type;
			typedef typename iterator_traits<T *>::reference			reference;
			typedef typename iterator_traits<T *>::pointer			pointer;
			typedef typename iterator_traits<T *>::difference_type	difference_type;
			// NOTE constructor;			
			_tree_iterator(): _iter(NULL) {}

			_tree_iterator(_treePointerNode iter) : _iter(iter) {}

			template<class T1, class Node>
			_tree_iterator(const _tree_iterator<T1, Node> & iter) : _iter(iter.base()){}

			//REVIEW - need to look if the iterator got an assignement operator
			_tree_iterator	&operator=(const _tree_iterator& iter){
				this->_iter = iter._iter;
				return (*this);
			}
			
			~_tree_iterator(){}

			_treePointerNode	base() const {
				return _iter;
			}
			reference operator*() const{
				return _iter->_data;
			}
			pointer operator->() const{
				return &(_iter->_data);
			}
			_treePointerNode leftMostNode(_treePointerNode rightNode){
				while(rightNode->_left)
					rightNode = rightNode->_left;
				return rightNode;
			}

			_tree_iterator operator++(int)
			{
				_treePointerNode result = this->_iter;
				++(*this);
				return result;
			}

			_tree_iterator operator++()
			{
				_treePointerNode parent = _iter->_parent;
				if (_iter->_right) // look for the leftmost node in that subtree;
				{
					_iter = leftMostNode(_iter->_right);
					return _iter;
				}
				while(parent != nullptr && parent->_right == _iter)
				{
					_iter = parent;
					parent = parent->_parent;
				}
				_iter = parent;
				return _iter;
			}

			_treePointerNode rightMostNode(_treePointerNode rightNode){
				while(rightNode->_right)
					rightNode = rightNode->_right;
				return rightNode;
			}

			_tree_iterator operator--(int)
			{
				_treePointerNode result = this->_iter;
				--(*this);
				return result;
			}

			_tree_iterator operator--()
			{
				_treePointerNode parent = _iter->_parent;
				if (_iter->_left)
				{
					_iter = rightMostNode(_iter->_left);
					return _iter;
				}
				while(parent != nullptr && parent->_left == _iter)
				{
					_iter = parent;
					parent = parent->_parent;
				}
				_iter = parent;
				return _iter;
			}
			friend bool operator== (const _tree_iterator& __x, const _tree_iterator& __y)
				{return __x._iter == __y._iter;}
			friend bool operator!= (const _tree_iterator& __x, const _tree_iterator& __y)
				{return !(__x == __y);}
		private:
			_treePointerNode	_iter;
	};

}

#endif