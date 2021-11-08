#ifndef _TREE_ITERATOR_HPP
#define _TREE_ITERATOR_HPP
#include <iostream>
#include <cstddef>


namespace ft{
template<class T, class _node>
	class _tree_iterator
	{
		public:
			typedef T			value_type;
			typedef value_type&	reference;
			typedef	value_type*	pointer;
			typedef	_node*		_treePointerNode;		
			// NOTE constructor;			
			explicit _tree_iterator(): _iter(NULL) {}
			explicit _tree_iterator(_treePointerNode iter) : _iter(iter) {}
			explicit _tree_iterator(_tree_iterator const& iter) : _iter(iter._iter){}
			~_tree_iterator();
			reference operator*() const{
				return _iter->_data;
			}
			pointer operator->() const{
				return &(_iter->data);
			}
			_tree_iterator& operator++(){
				if (_iter->right == nullptr)
					_iter = _iter->_parent;
				else (_iter->right)
				{
					// look for the leftmost node in that subtree;
				}
				return (*this);
			}
		private:
			_treePointerNode	_iter;
	};

}

#endif