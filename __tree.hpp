#ifndef __TREE_HPP
#define __TREE_HPP
#include <memory>
#include <iostream>
#include <math.h>
#include <cstddef>

namespace ft{
    template <class T>
	struct binaryTreeNode
	{
		T				_data;
		binaryTreeNode*	_parent;
		binaryTreeNode*	_left;
		binaryTreeNode*	_right;
		binaryTreeNode(T& data = NULL) : _data(data), _left(NULL), _right(NULL), _parent(NULL) {}
	};

	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
	class binarySearchTree
	{
		binaryTreeNode<T>*	_root;
		Alloc				_allocator;
		Compare				_compare;
		public:
		binarySearchTree() : _root(NULL), _allocator(Alloc()), _compare(Compare()){}
		int isempty(){
			return(_root == NULL);
		}
		void insert(T item){
			binaryTreeNode<T> *p = _allocator.allocate(1);
			_allocator.construct(p, item);
			if(isempty())
				_root = p;
			else
			{
				binaryTreeNode<T> *ptr;
				ptr = _root;
				while(ptr != NULL)
				{
					_parent = ptr;
					if(_compare(item.first, _parent->_data.first))
						ptr = ptr->_left;
					else if (item.first == _parent->_data.first)
						break;
					else
						ptr = ptr->_right;
				}
				if (_compare(item.first, _parent->_data.first))
					_parent->_left = p;
				else if (item == _parent->_data)
					_parent->_data.second = item.second;
				else
					_parent->_right = p;
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
}

#endif