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
		// NOTE check if T() works well, no segfault
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

		_node	*leftRotation(_node *node){
			_node *temp;

			temp = node;
			node = temp->_right;
			temp->_right = node->_left;
			node->_left = temp;
			temp->_parent = node;
			node->_parent = temp->_parent;
			if (temp->_right)
			 	temp->_right->_parent = temp;
			temp->height = 1 + (max(getHeight(temp->_left), getHeight(temp->_right)));
			node->height = 1 + (max(getHeight(node->_left), getHeight(node->_right)));
			return node;
		}

		_node	*rightRotation(_node *node){
			_node *temp;
			temp = node;
			node = temp->_left;
			temp->_left = node->_right;
			node->_right = temp;
			temp->_parent = node;
			if (temp->_left)
			 	temp->_left->_parent = temp;
			temp->height = 1 + (max(getHeight(temp->_left), getHeight(temp->_right)));
			node->height = 1 + (max(getHeight(node->_left), getHeight(node->_right)));
			return node;
		}

		int	balanceFactor(_node *node){
			if (node)
				return std::abs(getHeight(node->_left) - getHeight(node->_right));
			return (0); 
		}

		bool	leftheavy(_node *node){
			return (getHeight(node->_left) > getHeight(node->_right));
		}

		bool	rightheavy(_node *node){
			return (getHeight(node->_right) > getHeight(node->_left));
		}

		_node	*balanceTree(_node *node){
			if (balanceFactor(node) > 1)
			{
				if (leftheavy(node))
				{
					node = rightRotation(node);
				}
				else if (rightheavy(node))
				{
					node = leftRotation(node);
				}
			}
			return node;
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
			node = balanceTree(node);
			return node;
		}

		void	insert(T item){
		   if(isempty())
			{
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
		_node *findNode(_node *node, T data)
		{
			if(_compare(data.first, node->_data.first))
				node->_left = findNode(node->_left, data);
			else if (data.first == node->_data.first)
				return node;
			else
				node->_right = findNode(node->_right, data);
			return NULL;
		}

		_node *search(T data){
			if(isempty())
				return NULL;
			else
				return (findNode(_root, data));
		}

		_node *getSubtreeMinimum(_node *subtree)
		{
			while(subtree->_left)
				subtree = subtree->_left;
			return subtree;
		}

		_node	*DeleteNodeWithBalancing(_node *node, T data)
		{
			if(_compare(data.first, node->_data.first))
				node->_left = DeleteNodeWithBalancing(node->_left, data);
			else if (data.first == node->_data.first)
			{
				_node *temp;
				if (!(node->_left) || !(node->_right))
				{
					temp = node->_left ? node->_left : node->_right;
					if (temp) // there is a child;
						node = temp;
					else // there is no child;
					{
						temp = node;
						node = NULL;
					}	
					_allocator.deallocate(temp, 1);
				}
				else
				{
					_node *temp2;
					temp = getSubtreeMinimum(node->_right);
					node = temp;
					node->_right = DeleteNodeWithBalancing(node->_right, temp->_data);
				}
			}
			else
				node->_right = DeleteNodeWithBalancing(node->_right, data);
			if (node)
				node->height = 1 + (max(getHeight(node->_left), getHeight(node->_right)));
			node = balanceTree(node);
			return node;
		}

		void	delete_node(T data)
		{
			if (isempty())
				return;
			else
				DeleteNodeWithBalancing(_root, data);
		}
	};
}

#endif
