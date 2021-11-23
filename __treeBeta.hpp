#ifndef __TREEBETA_HPP
#define __TREEBETA_HPP
#include <memory>
#include <iostream>
#include <math.h>
#include <cstddef>

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

		binarySearchTree() : _root(NULL), _allocator(Alloc()), _compare(Compare()){
        }
		
        int isempty(){
			return(_root == NULL);
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

        binaryTreeNode<T> *insert(T& item){
            // NOTE to create the node;
            // binaryTreeNode<T> *p = _allocator.allocate(1);
			// _allocator.construct(p, item);
            if(isempty())
            {
                binaryTreeNode<T> *endNode = _allocator.allocate(1);
				
				_root = p;
				_root->height = 0 ;
				_root->_parent = endNode;
				endNode->_left = _root;
            }

        }
    }
}


#endif