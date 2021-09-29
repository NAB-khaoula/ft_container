#include <iterator>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(){
    std::vector<int> vect(3);
    std::cout << vect.size() << std::endl;
    std::cout << vect.capacity() << std::endl;
    std::cout << vect.max_size() << std::endl;
    std::cout << vect.empty() << std::endl;
    std::cout << "*********************" << std::endl;
    ft::vector<int> myVect(3);
    std::cout << myVect.size() << std::endl;
    std::cout << myVect.capacity() << std::endl;
    std::cout << myVect.max_size() << std::endl;
}


