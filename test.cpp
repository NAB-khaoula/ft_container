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
    std::cout << "------------- Library FT -------------" << std::endl;
    ft::map<char, int> mymap;
    ft::map<char, int>::iterator it;
    mymap['a'] = 50;
    mymap['b'] = 100;
    mymap['c'] = 150;
    mymap['d'] = 200;
    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase(it);
    // // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->first << '\n';
}

