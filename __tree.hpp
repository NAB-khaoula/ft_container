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
		int				height;
		binaryTreeNode*	_parent;
		binaryTreeNode*	_left;
		binaryTreeNode*	_right;
		binaryTreeNode(T& data) : _data(data), _left(NULL), _right(NULL), _parent(NULL), height(1) {}
	};

	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
	class binarySearchTree
	{
		typedef typename Alloc::difference_type	difference_type;
		Alloc				_allocator;
		Compare				_compare;
		binaryTreeNode<T>*	_root;
		public:
		binarySearchTree() : _root(NULL), _allocator(Alloc()), _compare(Compare()){}
		int isempty(){
			return(_root == NULL);
		}

		void insert(T item){
			//FIXME -  mem leak in one block (32 bytes)
			binaryTreeNode<T> *p = _allocator.allocate(1);
			_allocator.construct(p, item);
			binaryTreeNode<T> *parent;
			binaryTreeNode<T> *ptr;
			if(isempty())
			{
				binaryTreeNode<T> *endNode = _allocator.allocate(1);
				
				_root = p;
				_root->height = 0 ;
				_root->_parent = endNode;
				endNode->_left = _root;
			}
			else
			{
				ptr = _root;
				while(ptr != NULL)
				{
					parent = ptr;
					if(_compare(item.first, ptr->_data.first))
						ptr = ptr->_left;
					else if (item.first == ptr->_data.first)
					{
						_allocator.deallocate(p, 1);
						return;
					}
					else
						ptr = ptr->_right;
					parent->height += 1;
				}
				if (_compare(item.first, parent->_data.first))
				{
					p->_parent = parent;
					parent->_left = p;
				}
				else
				{
					parent->_right = p;
					p->_parent = parent;
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
		binaryTreeNode<T> *getSubtreeMaximum(binaryTreeNode<T> *subtree)
		{
			while(subtree->_right)
				subtree = subtree->_right;
			return subtree;
		}

		void	rightRotation(binaryTreeNode<T> *node){
			binaryTreeNode<T> *temp;

			temp = node->_left;
			node->_left = temp->_right;
			temp->_right->_parent = node;
			temp->_right = node;
			node->_parent = temp;
			// FIXME not always the root!!
			if(node == _root)
				_root = temp;
			else if (node->_parent->_left == node){
				node->_parent->_left = temp;
			}
			else
				node->_parent->_right = temp;
		}

		void	leftRotation(binaryTreeNode<T> *node){
			binaryTreeNode<T> *temp;

			temp = node->_right;
			node->_right = temp->_left;
			temp->_left->_parent = node;
			temp->_left = node;
			node->_parent = temp;
			// FIXME not always the root!!
			if(node == _root)
				_root = temp;
			else if (node->_parent->_left == node){
				node->_parent->_left = temp;
			}
			else
				node->_parent->_right = temp;
		}
		void	delete_node(T data)
		{
			if(isempty())
				return;
			else
			{
				binaryTreeNode<T> *tmp;
				binaryTreeNode<T> *tmp2;
				binaryTreeNode<T> *ptr = search(data);
				if(ptr)
				{
					if(!ptr->_left && !ptr->_right)
					{
						if(ptr->_parent->_left == ptr)
							ptr->_parent->_left = NULL;
						else
							ptr->_parent->_right = NULL;
						_allocator.deallocate(ptr, 1);
					}
					else if (!ptr->_left)
					{
						tmp = ptr;
						ptr = ptr->_right;
						_allocator.deallocate(tmp, 1);
					}
					else if (!ptr->_right)
					{
						tmp = ptr;
						ptr = ptr->_left;
						_allocator.deallocate(tmp, 1);
					}
					else
					{
						//NOTE:
						/*
							temp take the ptr;
							look for the maximum number of the subtree;
							the maximum node take the left and the right of ptr;
							ptr point on the last node
							dallocate temp;
						*/
						tmp2 = ptr;
						tmp = getSubtreeMaximum(ptr->_left);
						tmp->_right = ptr->_right;
						if(ptr->_parent->_left == ptr)
							ptr->_parent->_left = tmp;
						else
							ptr->_parent->_right = tmp;
						_allocator.deallocate(tmp2, 1);
					}
				}
			}
		}

		void	printNode(binaryTreeNode<T> *child)
		{
			if(child->_left != NULL)
				printNode(child->_left);
			std::cout << child->_data.first << ":" << child->_data.second << " ****height**** " << child->height << std::endl;
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