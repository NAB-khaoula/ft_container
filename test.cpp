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
	ft::map<int, int> mymap;
    // insert some values:
    mymap[10] = 10;
    mymap[20] = 20;
    mymap[30] = 30;
    mymap[40] = 40;
    mymap[50] = 50;
    mymap[60] = 60;
    ft::map<int, int>::iterator it = mymap.begin();
    it = mymap.find(20);
    mymap.erase(it);  // erasing by iterator
    // mymap.erase(30); // erasing by key
    // it = mymap.find(50);
    // mymap.erase(it, mymap.end()); // erasing by range
    // show content:
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

