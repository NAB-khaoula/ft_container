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
		binaryTreeNode(T& data = T()) : _data(data), height(1), _parent(NULL), _left(NULL), _right(NULL){}
	};

	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
	class binarySearchTree
	{
		typedef typename Alloc::difference_type	difference_type;
		typedef typename Alloc::size_type		size_type;
		typedef binaryTreeNode<T>				_node;
		Alloc				_allocator;
		Compare				_compare;
		_node*				_root;
		_node*				endNode;
		public:

		binarySearchTree() :  _allocator(Alloc()), _compare(Compare()), _root(NULL), endNode(NULL){
		}

		~binarySearchTree(){
			// FIXME - need to delete the endnode!!!!!
			// while(_root)
			// {
			// 	delete_node(_root->_data);
			// }
		}

		//FIXME - need to add assignment operator;

		int isempty() const{
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

		_node *get_min() const
		{
			_node *ptr = _root;
			if (ptr)
				while(ptr->_left)
					ptr = ptr->_left;
			return ptr;
		}

		_node *get_max() const
		{
			_node *ptr = _root;
			if (ptr)
				while(ptr->_right)
					ptr = ptr->_right;
			return ptr;
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
			node->_parent = temp->_parent;
			temp->_parent = node;
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
			node->_parent = temp->_parent;
			temp->_parent = node;
			if (temp->_left)
			 	temp->_left->_parent = temp;
			temp->height = 1 + (max(getHeight(temp->_left), getHeight(temp->_right)));
			node->height = 1 + (max(getHeight(node->_left), getHeight(node->_right)));
			return node;
		}

		int	balanceFactor(_node *node){
			if (node)
				return (getHeight(node->_left) - getHeight(node->_right));
			return (0); 
		}

		_node	*balanceTree(_node *node){
			if (balanceFactor(node) > 1 && balanceFactor(node->_left) >= 0)
				return (rightRotation(node));
			else if (balanceFactor(node) > 1 && balanceFactor(node->_left) < 0)
			{
				node->_left = leftRotation(node->_left);
				return (rightRotation(node));
			}
			else if (balanceFactor(node) < -1 && balanceFactor(node->_right) < 0)
			{

				return (leftRotation(node));
			}
			else if (balanceFactor(node) < -1 && balanceFactor(node->_right) >= 0)
			{
				node->_right = rightRotation(node->_right);
				return (leftRotation(node));
			}
			return node;
		}

		_node   *createNode(T item){
			_node *p = _allocator.allocate(1);
			_allocator.construct(p, item);
			return p;
		}

		_node   *insert_node(_node *node, T& item){
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
				endNode = _allocator.allocate(1);
				_root = _allocator.allocate(1);
				_allocator.construct(_root, item);
				_root->_parent = endNode;
				endNode->_left = _root;
			}
			else
			{
				_root = insert_node(_root, item);
				endNode->_left = _root;
			}
		}

		binaryTreeNode<T> *search(T const &data) const{
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

		binaryTreeNode<T> *searchTest(typename T::first_type const &data){
			binaryTreeNode<T> *ptr = _root;
			while(ptr)
			{
				if(_compare(data, ptr->_data.first))
					ptr = ptr->_left;
				else if (data == ptr->_data.first)
					break;
				else
					ptr = ptr->_right;
			}
			return ptr;
		}

		T	getSubtreeMinimum(_node *subtree)
		{
			while(subtree->_left)
				subtree = subtree->_left;
			return subtree->_data;
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
						_allocator.deallocate(temp, 1);
					}	
				}
				else
				{
					T item(getSubtreeMinimum(node->_right));
					_node *replacedNode = _allocator.allocate(1);
					_allocator.construct(replacedNode, item);
					replacedNode->_left = node->_left;
					replacedNode->_right = node->_right;
					replacedNode->_parent = node->_parent;
					temp = node;
					node = replacedNode;
					_allocator.deallocate(temp, 1);
					node->_right = DeleteNodeWithBalancing(node->_right, item);
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
				_root = DeleteNodeWithBalancing(_root, data);
		}
		size_type max_size() const{
			return (std::min<size_type>(std::numeric_limits<difference_type>::max(), _allocator.max_size()));
		}
	};
}

#endif
