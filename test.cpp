#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include "vector.hpp"

struct data
{
	int a;
	int b;
	data(int a = 1337, int b = 42) : a(a), b(b)
	{}
	data(const data& dt) {*this = dt;}
	data& operator= (const data& dt)
	{
		if (this != &dt)
		{
			this->a = dt.a;
			this->b = dt.b;
		}
		return (*this);
	}
};

int main(){
	ft::vector<int> vect;
	vect.push_back(1337);
	vect.push_back(42);
	vect.push_back(1997);
	vect.push_back(1962);
	vect.push_back(1963);
	// vect.resize(2);
	// ft::vector<int>::iterator iter(vect.begin());
	// std::cout << *iter << std::endl;
	// std::cout << *(iter + 1) << std::endl;
	// std::cout << *(iter + 2) << std::endl;
	// std::cout << *(iter + 3) << std::endl;
	// std::cout << *(iter + 3) << std::endl;
	// std::cout << "****" << vect.capacity() << std::endl; 
	// ft::vector<data> emptyData(2);
	// data tab(1997, 1996);
	// emptyData.resize(1, tab);
	// ft::vector<data>::iterator iterTest(emptyData.begin());
	// std::cout << iterTest[0].a << std::endl;
	// std::cout << iterTest[1].a << std::endl;
	// std::cout << iterTest[2].a << std::endl;
	// std::cout << emptyData.capacity() << std::endl;
	// std::cout << emptyData.size() << std::endl;
	// emptyData.resize(4);
	// std::cout << emptyData.capacity() << std::endl;
	// std::cout << iterTest[0].a << std::endl;
	// std::cout << iterTest[1].a << std::endl;
	// std::cout << iterTest[2].a << std::endl;
	// emptyData.push_back(tab);
	// std::cout << emptyData.capacity() << std::endl;
	// std::cout << emptyData.size() << std::endl;
	// ft::vector<data> emptyData;
	// std::cout << "Testing Capacity functions" << std::endl;
	// std::cout << emptyData.capacity()  << std::endl;
	// std::cout << emptyData.size() << std::endl;
	// std::cout << emptyData.max_size() << std::endl;
	// data tab(1337, 42);
	// emptyData.resize(3, tab);
	// ft::vector<data>::iterator iterTest(emptyData.begin());
	// std::cout << iterTest[0].a << std::endl;
	// std::cout << iterTest[1].a << std::endl;
	// std::cout << iterTest[2].a << std::endl;
	// std::cout << emptyData.capacity() << std::endl;
	// std::cout << emptyData.size() << std::endl;
	// std::cout << emptyData.max_size() << std::endl;
	// emptyData.resize(4);
	// std::cout << iterTest[0].a << std::endl;
	// std::cout << iterTest[1].a << std::endl;
	// std::cout << iterTest[2].a << std::endl;
	// std::cout << emptyData.capacity() << std::endl;
	// std::cout << emptyData.size() << std::endl;
	// std::cout << emptyData.max_size() << std::endl;
	ft::vector<int> vec;

   	vec.push_back(10);
   	vec.push_back(2);
   	vec.push_back(3);
   	vec.push_back(24);
   	vec.push_back(42);
   	vec.push_back(43);
   	vec.push_back(44);
	// std::cout << "**" << vec.capacity() << std::endl;
	// std::cout <<  "**" << vec.size() << std::endl;
	// std::cout << "return " << *(vec.erase(vec.begin(), vec.begin() + 4)) << std::endl;
	// for(int i = 0; i < vec.size() ; i++)
	// 	std::cout << "element:" << vec[i] << std::endl;
	// std::cout << "**" << vec.capacity() << std::endl;
	// std::cout <<  "**" << vec.size() << std::endl;
	// std::cout << "*********" << std::endl;
	// std::cout << vec.capacity() << std::endl;
	// std::cout << vec.size() << std::endl;
	// std::cout << "*********" << std::endl;
	// // std::cout << vec[0] << std::endl;
	// std::cout << vec[1] << std::endl;
	// std::cout << vec[2] << std::endl;
	// std::cout << vec[3] << std::endl;
	// std::cout << vec[4] << std::endl;
	// std::cout << vec[5] << std::endl;
	// vec.pop_back();
	// vec.erase(vec.begin());
	// std::cout << vec.capacity() << std::endl;
	// std::cout << vec.size() << std::endl;

	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200
	
	foo.swap(bar);
		
	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';
	
	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

}
