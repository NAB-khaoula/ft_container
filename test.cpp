#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include "vector.hpp"

// template <class T>
// struct iterator_traits {
//   typedef typename T::value_type value_type;
//   typedef typename T::difference_type difference_type;
//   typedef typename T::iterator_category iterator_category;
//   typedef typename T::pointer pointer;
//   typedef typename T::reference reference;
// };
	// template<class T>
	// struct iterator_traits<T*>
	// {
	// 	typedef ptrdiff_t							difference_type;
	// 	typedef T									value_type;
	// 	typedef T*									pointer;
	// 	typedef T&									reference;
	// 	typedef std::random_access_iterator_tag		iterator_category;
	// };

    // typedef typename iterator_traits<MyIterator>::value_type value_type; 

// template <class MyIterator>
// void do_something(MyIterator start, MyIterator end) {
//     typedef typename iterator_traits<MyIterator>::value_type value_type; 
//         value_type v;
//     while(start != end){
//         v = *start;
//         std::cout << v << std::endl;
//         start++;
//     }
// }

int main(){
    std::cout << "*****************************************************" << std::endl;
    ft::vector<int> 			bvect;
	bvect.push_back(1337);
	bvect.push_back(42);
	bvect.push_back(23);
	bvect.push_back(60);
	bvect.push_back(1997);
	ft::vector<int>::reverse_iterator	biter(bvect.begin());
    std::cout << biter[-2] << std::endl;
    std::cout << biter[-1] << std::endl;
    std::cout << biter[0] << std::endl;
    std::cout << biter[1] << std::endl;
    std::cout << biter[2] << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::vector<int> 			vect;
	vect.push_back(1337);
	vect.push_back(42);
	vect.push_back(23);
	vect.push_back(60);
	vect.push_back(1997);
	std::vector<int>::reverse_iterator	iter(vect.begin());
    std::cout << iter[-2] << std::endl;
    std::cout << iter[-1] << std::endl;
    std::cout << iter[0] << std::endl;
    std::cout << iter[1] << std::endl;
    std::cout << iter[2] << std::endl;
}
