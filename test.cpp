#include <iterator>
#include <vector>
#include <iostream>
#include "vector.hpp"

struct ms
{
    int a;
    int b;
    ms(int a = 1,int  b = 2): a(a), b(b){
        std::cout << "constructor called" << std::endl;
    }
    ms(ms &val): a(val.a), b(val.b){

        std::cout << "copy constructor called" << std::endl;
    }
    ~ms(){}
};

int main(){
    int *arr = new int(6);
    ms m(3, 4);
    std::vector<ms> vect(3);
    // std::cout << vect.size() << std::endl;
    // std::cout << vect.capacity() << std::endl;
    // // std::cout << vect.max_size() << std::endl;
    // // std::cout << vect.empty() << std::endl;
    // std::cout << "*********************" << std::endl;
    // ft::vector<int> myVect(3);
    // std::cout << myVect.size() << std::endl;
    // std::cout << myVect.capacity() << std::endl;
    // std::cout << myVect.max_size() << std::endl;
}


