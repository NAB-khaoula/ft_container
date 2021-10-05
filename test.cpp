#include <iterator>
#include <vector>
#include <iostream>
#include "vector.hpp"


// my own datatype to provide more test!!
// struct ms
// {
// 	int a;
// 	int b;
// 	ms(int a = 1,int  b = 2): a(a), b(b){
// 		std::cout << "constructor called" << std::endl;
// 	}
// 	ms(ms &val): a(val.a), b(val.b){

// 		std::cout << "copy constructor called" << std::endl;
// 	}
// 	~ms(){}
// };


template <class MyIterator>
void do_something(MyIterator start, MyIterator end) {
	typedef typename std::iterator_traits<MyIterator>::value_type value_type; 
	// typedef typename MyIterator::value_type value_type; 
	value_type v = *start;
	std::cout << v << std::endl;
}

int main(){
	std::vector<int> 			vect;
	vect.push_back(1337);
	vect.push_back(42);
	vect.push_back(24);
	std::vector<int>::iterator	iter = vect.begin();
	ft::vector<int>				pseudoVect;
	pseudoVect.push_back(1337);
	pseudoVect.push_back(42);
	pseudoVect.push_back(24);
	ft::vector<int>::iterator	pseudoIter = pseudoVect.begin();
	std::cout << *iter << std::endl;
	std::cout << *pseudoIter << std::endl;
	// std::vector<int> vect;
	// vect.push_back(3);
	// vect.push_back(3);
	// vect.push_back(3);
	// do_something(vect.begin(), vect.end());
	// int tab[] = {1,2,3};
	// do_something(&tab[0], &tab[3]);
}


