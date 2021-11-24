#ifndef __TREEBETA_HPP
#define __TREEBETA_HPP
#include <memory>
#include <iostream>
#include <cmath>
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
		// NOTE check it T() works well, no segfault
		binaryTreeNode(T& data = T()) : _data(data), _left(NULL), _right(NULL), _parent(NULL), height(1) {}
	};

	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
	class binarySearchTree
	{
		typedef typename Alloc::difference_type	difference_type;
		typedef binaryTreeNode<T>		_node;
		Alloc				_allocator;
		Compare				_compare;
		_node*	_root;
		public:

		binarySearchTree() : _root(NULL), _allocator(Alloc()), _compare(Compare()){
		}
		
		int isempty(){
			return(_root == NULL);
		}

		void	printNode(_node *child)
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

		_node *get_min()
		{
			_node *ptr = _root;
			while(ptr->_left)
				ptr = ptr->_left;
			return ptr;
		}

		_node *get_max()
		{
			_node *ptr = _root;
			while(ptr->_right)
				ptr = ptr->_right;
			return ptr;
		}
		_node *getSubtreeMaximum(_node *subtree)
		{
			while(subtree->_right)
				subtree = subtree->_right;
			return subtree;
		}
		int		getHeight(_node *node)
		{
			if (node)
				return node->height;
			return 0;
		}

		int		max(int a, int b)
		{
			return (a > b ? a : b);
		}

		void	rightRotation(binaryTreeNode<T> *node){
			binaryTreeNode<T> *temp;
			temp = node->_left;
			std::cout << "debugging" << std::endl;
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

		int	balanceFactor(_node *node){
			if (node)
				return std::abs(getHeight(node->_left) - getHeight(node->_right));
			return (0); 
		}

		bool	leftheavy(_node *node){
			int _balanceFactor = 0;
			_balanceFactor = balanceFactor(node);
			return (_balanceFactor > 1 && getHeight(node->_left) > getHeight(node->_right));
		}

		bool	rightheavy(_node *node){
			int _balanceFactor = 0;
			_balanceFactor = balanceFactor(node);
			return (_balanceFactor > 1 && getHeight(node->_right) > getHeight(node->_left));
		}

		void	balanceTree(_node *node){
			if (leftheavy(node))
			{
				// leftRotation(node);
				// std::cout << node->_data.first << std::endl;
			}
			else if (rightheavy(node))
			{
				std::cout << node->_right->_data.first << std::endl;
				// rightRotation(node->_right);

			}
		}

		_node   *insert_node(_node *node, T item){
			if (node == NULL)
			{
				_node *p = _allocator.allocate(1);
				_allocator.construct(p, item);
				return p;
			}
			if(_compare(item.first, node->_data.first))
			{
				node->_left = insert_node(node->_left, item);
				node->_left->_parent = node;
			}
			else if (item.first == node->_data.first)
				return node;
			else
			{
				node->_right = insert_node(node->_right, item);
				node->_right->_parent = node;
			}
			node->height = 1 + (max(getHeight(node->_left), getHeight(node->_right)));
			balanceTree(node);
			return node;
		}

		void insert(T item){
		   if(isempty())
			{
				// FIXME  need to call the constructor;
				T nothing = T();
				_node *endNode = _allocator.allocate(1);
				_allocator.construct(endNode, nothing);
				_root = _allocator.allocate(1);
				_allocator.construct(_root, item);
				_root->_parent = endNode;
				endNode->_left = _root;
			}
			else
			{
				_root = insert_node(_root, item);
			}
		}
	};
}

#endif
