#include <iostream>
#include <vector>
#include <iterator>

struct data
{
    int a;
    int b;
    data() {std::cout << "Constructor Default\n";}
    data(int a = 1337, int b = 42) : a(a), b(b)
    {
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "Constructor parametrse\n";}
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
	std::vector<int> 			vect;
	vect.push_back(1337);
	vect.push_back(42);
	vect.push_back(23);
	vect.push_back(6);
	vect.push_back(1997);
	std::vector<int>::iterator	iter(vect.begin());
	std::cout << *iter << std::endl;
	std::cout << *(iter.base()) << std::endl;
	std::cout << *(++iter) << std::endl;
	std::cout << *(--iter) << std::endl;
	std::cout << *(iter++) << std::endl;
	std::cout << *(iter--) << std::endl;
	std::cout << *(iter + 2) << std::endl;
	std::cout << *(iter - 2) << std::endl;
	std::vector<int>::iterator	iterAssignment(iter);
	iterAssignment += 3;
	std::cout << *iterAssignment << std::endl;
	iterAssignment -= 3;
	std::cout << *iterAssignment << std::endl;
	std::cout << iter[2] << std::endl;
	std::cout << (iterAssignment == iter) << std::endl;
	iterAssignment += 1;
	std::cout << (iterAssignment == iter) << std::endl;
	std::cout << (iterAssignment != iter) << std::endl;
	std::cout << (iterAssignment < iter) << std::endl;
	std::cout << (iterAssignment <= iter) << std::endl;
	std::cout << (iterAssignment > iter) << std::endl;
	std::cout << (iterAssignment >= iter) << std::endl;
	// while(iter != vect.end())
	// 	std::cout << *(iter++)<< std::endl;
	std::cout << "Testing with a struct!" << std::endl;
	std::vector<data>			Data;
	Data.push_back(data(10, 20));
	Data.push_back(data(100, 200));
	Data.push_back(data(1000, 2000));
	Data.push_back(data(10000, 20000));
	Data.push_back(data(100000, 2000000));
	Data.push_back(data(1000000, 20000000));
	Data.push_back(data(10000000, 20000000));
	std::vector<data>::iterator dataIterator(Data.begin());
	std::vector<data>::iterator	dataAssignment(dataIterator);
	std::cout << dataIterator->a << std::endl;
	std::cout << dataIterator->b << std::endl;
	std::cout << (dataIterator == dataAssignment) << std::endl;
	std::cout << (dataIterator != dataAssignment) << std::endl;
	std::cout << (dataIterator < dataAssignment) << std::endl;
	std::cout << (dataIterator <= dataAssignment) << std::endl;
	std::cout << (dataIterator > dataAssignment) << std::endl;
	std::cout << (dataIterator >= dataAssignment) << std::endl;
}