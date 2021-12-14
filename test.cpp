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

int main()
{
	{
		ft::map<int,int> mymap;
		for(size_t i = 0 ; i< 1000000 ; i++)
			mymap[i] = i;
		ft::map<int,int>::iterator it = mymap.begin();
		for(int i = 0; i < 1000000; i++)
			it++;
            // mymap.erase(i);
		mymap.erase(mymap.begin(), it);
	}
}

