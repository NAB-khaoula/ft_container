#ifndef __TREE_HPP
#define __TREE_HPP
#include <memory>
#include <iostream>
#include <math.h>
#include <cstddef>
// #include "_tree_iterator.hpp"

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
		typedef typename Alloc::difference_type	difference_type;
		
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
			binaryTreeNode<T> *parent;
			if(isempty())
			{
				binaryTreeNode<T> *endNode = _allocator.allocate(1);
				_root = p;
				_root->_parent = endNode;
				endNode->_left = _root;
			}
			else
			{
				binaryTreeNode<T> *ptr;
				ptr = _root;
				while(ptr != NULL)
				{
					parent = ptr;
					if(_compare(item.first, ptr->_data.first))
						ptr = ptr->_left;
					else if (item.first == ptr->_data.first)
						break;
					else
						ptr = ptr->_right;
				}
				if (_compare(item.first, parent->_data.first))
				{
					p->_parent = parent;
					parent->_left = p;
					// parent->_parent = parent;
				}
				else if (item == parent->_data)
				{
					// parent->_parent = parent;
					parent->_data.second = item.second;
				}
				else
				{
					parent->_right = p;
					p->_parent = parent;
					// parent->_parent = parent;
				}
			}
		}

		binaryTreeNode<T> *search(T data){
			binaryTreeNode<T> *ptr = _root;
			while(ptr)
			{
				if(_compare(data.first, ptr->_data.first))
					ptr = ptr->_left;
				else if (data.first == ptr->_data.first)
					break;
				else
					ptr = ptr->_right;
			}
			return ptr;
		}

		binaryTreeNode<T> *get_min()
		{
			binaryTreeNode<T> *ptr = _root;
			while(ptr->_left)
				ptr = ptr->_left;
			return ptr;
		}

		binaryTreeNode<T> *get_max()
		{
			binaryTreeNode<T> *ptr = _root;
			while(ptr->_right)
				ptr = ptr->_right;
			return ptr;
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