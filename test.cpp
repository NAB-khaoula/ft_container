#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include "vector.hpp"
#include <utility>
// #include "map.hpp"
#include <map>

// struct data
// {
// 	int a;
// 	int b;
// 	data(int a = 1337, int b = 42) : a(a), b(b)
// 	{}
// 	data(const data& dt) {*this = dt;}
// 	data& operator= (const data& dt)
// 	{
// 		if (this != &dt)
// 		{
// 			this->a = dt.a;
// 			this->b = dt.b;
// 		}
// 		return (*this);
// 	}
// };

// template <class T1, class T2> 
// 	struct pair{
// 		typedef T1  first_type;
// 		typedef T2  second_type;
// 		first_type first;
// 		second_type second;
// 		pair():first(first_type()), second(second_type()){}
// 		pair (const first_type& a, const second_type& b): first(a), second(b){}
// 		template<class U, class V>
// 		pair (const pair<U,V>& pr): first(pr.first), second(pr.second){}
// 		pair& operator= (const pair& pr){
// 				first = pr.first;
// 				second = pr.second;
// 				return (*this);
// 		}
// 		template <class U, class V>
// 			friend bool operator== (const pair<U,V>& lhs, const pair<U,V>& rhs)
// 			{
// 				return(lhs.first == rhs.first && lhs.second == rhs.second);
// 			}
		
// 		template <class U, class V>
// 			friend bool operator!= (const pair<U,V>& lhs, const pair<U,V>& rhs)
// 			{
// 				return(!(lhs == rhs));
// 			}
		
// 		template <class U, class V>
// 			friend bool operator<  (const pair<U,V>& lhs, const pair<U,V>& rhs)
// 			{
// 				return (lhs.first<rhs.first && lhs.second<rhs.second); 
// 			}

// 		template <class U, class V>
// 			friend bool operator<= (const pair<U,V>& lhs, const pair<U,V>& rhs)
// 			{ 
// 				return (!(rhs<lhs)); 
// 			}

// 		template <class U, class V>
// 			friend bool operator>  (const pair<U,V>& lhs, const pair<U,V>& rhs)
// 			{ 
// 				return rhs<lhs;
// 			}

// 		template <class U, class V>
// 			friend bool operator>= (const pair<U,V>& lhs, const pair<U,V>& rhs)
// 			{
// 				return !(lhs<rhs);
// 			}
// 	};
// 	template <class T1,class T2>
//   		pair<T1,T2> make_pair (T1 x, T2 y)
//   		{
//     		return ( pair<T1,T2>(x,y) );
//   		}

// 	template <class T>
// 	struct binaryTreeNode
// 	{
// 		T				_data;
// 		binaryTreeNode*	_left;
// 		binaryTreeNode*	_right;
// 	};

// 	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
// 	class binarySearchTree
// 	{
// 		binaryTreeNode<T>*	_root;
// 		Alloc				_allocator;
// 		Compare				_compare;
// 		public:
// 		binarySearchTree() : _root(NULL), _allocator(Alloc()), _compare(Compare())
// 		{
// 			// _root = NULL;
// 			// _allocator = Alloc();
// 			// _compare = Compare();
// 		}
// 		int isempty()
// 		{
// 			return(_root == NULL);
// 		}
// 		void insert(T item){
// 			binaryTreeNode<T> *p = _allocator.allocate(1);
// 			binaryTreeNode<T> *parent;
// 			p->_data = item;
// 			p->_left = NULL;
// 			p->_right = NULL;
// 			parent = NULL;
// 			if(isempty())
// 				_root = p;
// 			else
// 			{
// 				binaryTreeNode<T> *ptr;
// 				ptr = _root;
// 				while(ptr != NULL)
// 				{
// 					parent = ptr;
// 					if(_compare(item.first, parent->_data.first))
// 						ptr = ptr->_left;
// 					else if (item.first == parent->_data.first)
// 						break;
// 					else
// 						ptr = ptr->_right;
// 				}
// 				if (_compare(item.first, parent->_data.first))
// 					parent->_left = p;
// 				else if (item == parent->_data)
// 					parent->_data = item;
// 				else
// 					parent->_right = p;
// 			}
// 		}
// 		void	printNode(binaryTreeNode<T> *child)
// 		{
// 			if(child->_left != NULL)
// 				printNode(child->_left);
// 			std::cout << child->_data.first << ":" << child->_data.second << std::endl;
// 			if (child->_right != NULL)
// 				printNode(child->_right);
// 		}

// 		void	printTree()
// 		{
// 			if(_root != NULL)
// 				printNode(_root);
// 			else
// 				std::cout << "empty tree!" << std::endl;
// 		}
// 	};

int main(){
	// binarySearchTree<pair<std::string, int>, std::less<std::string> > bst;
	// bst.insert(make_pair<std::string, int>("esixth",8));
	// bst.insert(make_pair<std::string, int>("afirst", 13));
	// bst.insert(make_pair<std::string, int>("l",1));
	// bst.insert(make_pair<std::string, int>("bsecond", 12));
	// bst.insert(make_pair<std::string, int>("cthird",11));
	// bst.insert(make_pair<std::string, int>("j",3));
	// bst.insert(make_pair<std::string, int>("fourth",10));
	// bst.insert(make_pair<std::string, int>("i",4));
	// bst.insert(make_pair<std::string, int>("dfifth",9));
	// bst.insert(make_pair<std::string, int>("fseventh",7));
	// bst.insert(make_pair<std::string, int>("geighth",6));
	// bst.insert(make_pair<std::string, int>("h",5));
	// bst.insert(make_pair<std::string, int>("k",2));
	// bst.printTree();
	// **********************
	// ft::map<int, std::string> _map;
	// _map.insert(ft::make_pair<int, std::string>(10, "root"));
	// _map.insert(ft::make_pair<int, std::string>(30, "right"));
	// _map.insert(ft::make_pair<int, std::string>(5, "left"));
	// _map.insert(ft::make_pair<int, std::string>(7, "left right"));
	// _map.insert(ft::make_pair<int, std::string>(1, "left left"));
	// _map.insert(ft::make_pair<int, std::string>(45, "right right"));
	// _map.insert(ft::make_pair<int, std::string>(12, "right left"));
	// _map.insert(ft::make_pair<int, std::string>(8, "left right left"));
	// _map.insert(ft::make_pair<int, std::string>(9, "left right right"));
	// _map.insert(ft::make_pair<int, std::string>(12, "right left"));
	// _map.insert(ft::make_pair<int, std::string>(11, "right left left"));
	// _map.insert(ft::make_pair<int, std::string>(17, "right left right"));
	// _map.insert(ft::make_pair<int, std::string>(44, "right right left"));
	// _map.insert(ft::make_pair<int, std::string>(50, "right right right"));
	// _map.insert(ft::make_pair<int, std::string>(46, "right right right left"));
	// _map.insert(ft::make_pair<int, std::string>(60, "right right right right"));
	// _map.printTree();
	std::vector<int> vec;
	std::map<int, int> _map;
	_map.insert(std::make_pair<int, int>(20,20));
	_map.insert(std::make_pair<int, int>(10,10));
	_map.insert(std::make_pair<int, int>(45,45));
	_map.insert(std::make_pair<int, int>(5,5));
	_map.insert(std::make_pair<int, int>(15,15));
	_map.insert(std::make_pair<int, int>(30,30));
	_map.insert(std::make_pair<int, int>(50,50));
	std::map<int, int>::iterator it = _map.end();
	std::cout << it->first << std::endl;
	it--;
	std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	return 0;
}

