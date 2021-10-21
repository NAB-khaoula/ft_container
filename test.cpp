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
	// ft::vector<int> vect;
	// vect.push_back(1337);
	// vect.push_back(42);
	// vect.push_back(1997);
	// vect.push_back(1962);
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

	size_t tab[5] = {1,2,60,4,5};

	ft::vector<size_t> vec(tab, tab + 5);
	// for(int i = 0; i < 5; i++)
	// 	std::cout << vec[i] << std::endl;
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;
	vec.assign(tab, tab + 7);
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
	vec.insert(vec.begin() + 3, 3);
   	// vec.push_back(10);
   	// vec.push_back(2);
   	// vec.push_back(3);
   	// vec.push_back(4);
   	// vec.push_back(4);
   	// vec.push_back(4);
	// std::cout << vec.capacity() << std::endl;
	// std::cout << vec.size() << std::endl;
	// vec.pop_back();
	// vec.erase(vec.begin());
	// std::cout << vec.capacity() << std::endl;
	// std::cout << vec.size() << std::endl;

}
