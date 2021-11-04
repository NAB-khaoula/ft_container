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
	template <class T1, class T2> 
	struct pair{
		typedef T1  first_type;
		typedef T2  second_type;
		first_type first;
		second_type second;
		pair():first(first_type()), second(second_type()){}
		pair (const first_type& a, const second_type& b): first(a), second(b){}
		template<class U, class V>
		pair (const pair<U,V>& pr){
			first = pr.first;
			second = pr.second;
		}
		pair& operator= (const pair& pr){
				first = pr.first;
				second = pr.second;
				return (*this);
		}
		template <class U, class V>
			friend bool operator== (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return(lhs.first == rhs.first && lhs.first == rhs.second);
			}
		
		template <class U, class V>
			friend bool operator!= (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return(!(lhs == rhs));
			}
		
		template <class U, class V>
			friend bool operator<  (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return (lhs.first<rhs.first && lhs.second<rhs.second); 
			}

		template <class U, class V>
			friend bool operator<= (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{ 
				return (!(rhs<lhs)); 
			}

		template <class U, class V>
			friend bool operator>  (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{ 
				return rhs<lhs;
			}

		template <class U, class V>
			friend bool operator>= (const pair<U,V>& lhs, const pair<U,V>& rhs)
			{
				return !(lhs<rhs);
			}
	};
	template <class T1,class T2>
  		pair<T1,T2> make_pair (T1 x, T2 y)
  		{
    		return ( pair<T1,T2>(x,y) );
  		}

	template <class T>
	struct binaryTreeNode
	{
		T				_data;
		binaryTreeNode*	_left;
		binaryTreeNode*	_right;
	};

	template <class T, class Compare, class Alloc = std::allocator<binaryTreeNode<T> > >
	class binarySearchTree
	{
		binaryTreeNode<T>*	_root;
		Alloc				_allocator;
		Compare				_compare;
		public:
		binarySearchTree()
		{
			_root = NULL;
			_allocator = Alloc();
			_compare = Compare();
		}
		int isempty()
		{
			return(_root == NULL);
		}
		void insert(T item){
			binaryTreeNode<T> *p = _allocator.allocate(1);
			binaryTreeNode<T> *parent;
			p->_data = item;
			p->_left = NULL;
			p->_right = NULL;
			parent = NULL;
			if(isempty())
				_root = p;
			else
			{
				binaryTreeNode<T> *ptr;
				ptr = _root;
				while(ptr != NULL)
				{
					parent = ptr;
					if(_compare(item.first, parent->_data.first))
						ptr = ptr->_left;
					else if (item.first == parent->_data.first)
						break;
					else
						ptr = ptr->_right;
				}
				if (_compare(item, parent->_data))
					parent->_left = p;
				else if (item.first == parents)
					parent->_data.value = item.value;
				else
					parent->_right = p;
			}
		}
		void	printNode(binaryTreeNode<T> *child)
		{
			if(child->_left != NULL)
				printNode(child->_left);
			std::cout << child->_data << std::endl;
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

int main(){
	binarySearchTree<pair<std::string, int>, std::less<int> > bst;
	bst.insert(make_pair<std::string, int>("afirst", 13));
	bst.insert(make_pair<std::string, int>("bsecond", 12));
	bst.insert(make_pair<std::string, int>("cthird",11));
	bst.insert(make_pair<std::string, int>("fourth",10));
	bst.insert(make_pair<std::string, int>("dfifth",9));
	bst.insert(make_pair<std::string, int>("esixth",8));
	bst.insert(make_pair<std::string, int>("fseventh",7));
	bst.insert(make_pair<std::string, int>("geighth",6));
	bst.insert(make_pair<std::string, int>("h",5));
	bst.insert(make_pair<std::string, int>("i",4));
	bst.insert(make_pair<std::string, int>("j",3));
	bst.insert(make_pair<std::string, int>("k",2));
	bst.insert(make_pair<std::string, int>("l",1));
	bst.printTree();
	std::less<int> less;
	return 0;
}

