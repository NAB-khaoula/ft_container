#include <iterator>
#include <vector>
#include <iostream>
// #include "vector.hpp"

int main(){
    std::vector<int> vect;
    vect.push_back(1337);
    vect.push_back(42);
    vect.push_back(19);
    std::cout << vect[0] << std::endl;
    std::cout << vect[1] << std::endl;
    std::cout << vect[2] << std::endl;
    std::vector<int> v2(vect.begin(), vect.end());
    std::cout << v2[0] << std::endl;
    std::cout << v2[1] << std::endl;
    std::cout << v2[2] << std::endl;
    // ft::vector<int> v3(vect.begin(), vect.end());
    // std::cout << vect.capacity() << std::endl;
    // std::cout << tester.capacity() << std::endl;
}
