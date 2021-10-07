#include <iterator>
#include <vector>
#include <iostream>
#include "vector.hpp"


int main(){
	std::vector<int> 			vect;
	ft::vector<int>				pseudoVect;
	vect.push_back(1337);
	pseudoVect.push_back(1337);
	vect.push_back(42);
	pseudoVect.push_back(42);
	vect.push_back(24);
	pseudoVect.push_back(24);
	vect.push_back(30);
	pseudoVect.push_back(30);
	std::vector<int>::iterator	iter = vect.begin();
	ft::vector<int>::iterator	pseudoIter = pseudoVect.begin();
	// std::cout << *iter << std::endl;
	// std::cout << *pseudoIter << std::endl;
	// std::cout << *(++iter) << std::endl;
	// std::cout << *(++pseudoIter) << std::endl;
	// std::cout << *(iter + 2) << std::endl;
	// std::cout << *(pseudoIter + 2) << std::endl;
	// std::cout << iter[2] << std::endl;
	// std::cout << pseudoIter[2] << std::endl;
	// std::cout << iter[2] << std::endl;
	// std::cout << pseudoIter[2] << std::endl;
	while(iter != vect.end())
		std::cout << *(iter++)<< std::endl;
	while(pseudoIter != pseudoVect.begin() + 4)
		std::cout << *(pseudoIter++)<< std::endl;
}


