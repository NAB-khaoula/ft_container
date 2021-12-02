#include <iostream>
// #include <vector>
// #include <memory>
// #include <iterator>
// #include "vector.hpp"
// #include <utility>
#include "map.hpp"
#include "vector.hpp"
#include "reverse_iterator.hpp"
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

void	printOriginalMap(std::map<int, int>::iterator it_begin, std::map<int, int>::iterator it_end){
	while(it_begin != it_end )
	{
		std::cout << it_begin->first << " : " << it_begin->second << std::endl;
		it_begin++;
	}
}

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
	// ft::map<int, int>::binarySearchTree _map;
	// _map.insert(ft::make_pair<int, int>(20,20));
	// _map.insert(ft::make_pair<int, int>(10,10));
	// _map.insert(ft::make_pair<int, int>(45,45));
	// _map.insert(ft::make_pair<int, int>(5,5));
	// _map.insert(ft::make_pair<int, int>(15,15));
	// _map.insert(ft::make_pair<int, int>(30,30));
	// _map.insert(ft::make_pair<int, int>(50,50));
	// _map.printTree();
	// it--;
	// std::cout << it->first << std::endl;
	// it--;
	// std::cout << it->first << std::endl;
	// it--;
	// std::cout << it->first << std::endl;
	// it--;
	// std::cout << it->first << std::endl;
	// it--;
	// std::cout << it->first << std::endl;
	// _map.insert(ft::make_pair<int, int>(20,0));
	// _map.insert(ft::make_pair<int, int>(30,0));
	// _map.insert(ft::make_pair<int, int>(40,0));
	// _map.insert(ft::make_pair<int, int>(50,0));
	// _map.insert(ft::make_pair<int, int>(60,0));
	// _map.insert(ft::make_pair<int, int>(70,0));
	// _map.insert(ft::make_pair<int, int>(80,0));
	// _map.insert(ft::make_pair<int, int>(95,0));
	// _map.insert(ft::make_pair<int, int>(100,0));
	// _map.insert(ft::make_pair<int, int>(45,0));
	// _map.insert(ft::make_pair<int, int>(33,0));
	// _map.insert(ft::make_pair<int, int>(25,0));
	// _map.insert(ft::make_pair<int, int>(10,0));

	// _map.insert(ft::make_pair<int, int>(30,0));
	// _map.insert(ft::make_pair<int, int>(20,0));
	// _map.insert(ft::make_pair<int, int>(21,0));

	{
		ft::map<int, int> origin_map;
		origin_map.insert(ft::make_pair<int, int>(50,10));
    	origin_map.insert(ft::make_pair<int, int>(50,11));
    	origin_map.insert(ft::make_pair<int, int>(40,11));
    	origin_map.insert(ft::make_pair<int,int>(30,12));
    	origin_map.insert(ft::make_pair<int, int>(20,12));
    	origin_map.insert(ft::make_pair<int, int>(61,12));
    	origin_map.insert(ft::make_pair<int, int>(70,12));
    	origin_map.insert(ft::make_pair<int, int>(55,12));
    	origin_map.insert(ft::make_pair<int, int>(41,12));
    	origin_map.insert(ft::make_pair<int, int>(10,12));
    	origin_map.insert(ft::make_pair<int, int>(5,12));
    	origin_map.insert(ft::make_pair<int, int>(2,12));
		ft::map<int, int>::iterator it_test = origin_map.begin();
		std::cout << "******* print tree *********" << std::endl;
		origin_map.Treeprint();
		std::cout << it_test->first << " : " << it_test->second << std::endl;
		it_test++;
		std::cout << it_test->first << " : " << it_test->second << std::endl;
		it_test--;
		std::cout << it_test->first << " : " << it_test->second << std::endl;
		it_test = origin_map.end();
		std::cout << it_test->first << " : " << it_test->second << std::endl;
	}
	
	std::cout << "*********************************" << std::endl;
	{
		std::map<int, int> origin_map;
		origin_map.insert(std::make_pair<int, int>(50,10));
    	origin_map.insert(std::make_pair<int,int>(40,11));
    	origin_map.insert(std::make_pair<int,int>(30,12));
    	origin_map.insert(std::make_pair<int, int>(20,12));
    	origin_map.insert(std::make_pair<int, int>(61,12));
    	origin_map.insert(std::make_pair<int, int>(70,12));
    	origin_map.insert(std::make_pair<int, int>(55,12));
    	origin_map.insert(std::make_pair<int, int>(41,12));
    	origin_map.insert(std::make_pair<int, int>(10,12));
    	origin_map.insert(std::make_pair<int, int>(5,12));
    	origin_map.insert(std::make_pair<int, int>(2,12));
		std::map<int, int>::iterator it_test = origin_map.begin();
		printOriginalMap(origin_map.begin(), origin_map.end());
		std::cout << it_test->first << " : " << it_test->second << std::endl;
		it_test++;
		std::cout << it_test->first << " : " << it_test->second << std::endl;
		it_test--;
		std::cout << it_test->first << " : " << it_test->second << std::endl;
		it_test = origin_map.end();
		std::cout << it_test->first << " : " << it_test->second << std::endl;
	}
}

