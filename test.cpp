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
	std::cout << "****** original *******" << std::endl;
	{  
	  	std::map<char,int> mymap;
  		std::map<char,int>::iterator itlow,itup;

  		mymap['a']=20;
  		mymap['b']=40;
  		mymap['c']=60;
  		mymap['d']=80;
  		mymap['e']=100;

  		itlow=mymap.lower_bound ('b');  // itlow points to b
  		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  		mymap.erase(itlow,itup);        // erases [itlow,itup)

  		// print content:
  		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << "****** duplicated *******" << std::endl;
	{
		ft::map<char,int> mymap;
  		ft::map<char,int>::iterator itlow,itup;

  		mymap['a']=20;
  		mymap['b']=40;
  		mymap['c']=60;
  		mymap['d']=80;
  		mymap['e']=100;

  		itlow=mymap.lower_bound ('b');  // itlow points to b
  		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  		mymap.erase(itlow,itup);        // erases [itlow,itup)

  		// print content:
  		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << '\n';
	}
}

