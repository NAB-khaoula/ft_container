#include <iostream>
#include <vector>
#include <iterator>


int main(){
	std::vector<int> 			vect;
	vect.push_back(1337);
	vect.push_back(42);
	vect.push_back(23);
	vect.push_back(6);
	vect.push_back(1997);
	std::vector<int>::iterator	iter = vect.begin();
	std::cout << *iter << std::endl;
	std::cout << *(++iter) << std::endl;
	std::cout << *(iter + 2) << std::endl;
	std::cout << iter[2] << std::endl;
	std::cout << "dif" << std::endl;
	// while(iter != vect.end())
	// 	std::cout << *(iter++)<< std::endl;
}