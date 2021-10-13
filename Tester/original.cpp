#include <iostream>
#include <vector>
#include <memory>
#include <iterator>

struct data
{
    int a;
    int b;
    data(int a = 1337, int b = 42) : a(a), b(b){}
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
	// std::vector<int> 			vect;
	// vect.push_back(1337);
	// vect.push_back(42);
	// vect.push_back(23);
	// vect.push_back(6);
	// vect.push_back(1997);
	// std::vector<int>::iterator	iter(vect.begin());
	// std::cout << *iter << std::endl;
	// std::cout << *(iter.base()) << std::endl;
	// std::cout << *(++iter) << std::endl;
	// std::cout << *(--iter) << std::endl;
	// std::cout << *(iter++) << std::endl;
	// std::cout << *(iter--) << std::endl;
	// std::cout << *(iter + 2) << std::endl;
	// std::cout << *(iter - 2) << std::endl;
	// std::vector<int>::iterator	iterAssignment(iter);
	// iterAssignment += 3;
	// std::cout << *iterAssignment << std::endl;
	// iterAssignment -= 3;
	// std::cout << *iterAssignment << std::endl;
	// std::cout << iter[2] << std::endl;
	// std::cout << (iterAssignment == iter) << std::endl;
	// iterAssignment += 1;
	// std::cout << (iterAssignment == iter) << std::endl;
	// std::cout << (iterAssignment != iter) << std::endl;
	// std::cout << (iterAssignment < iter) << std::endl;
	// std::cout << (iterAssignment <= iter) << std::endl;
	// std::cout << (iterAssignment > iter) << std::endl;
	// std::cout << (iterAssignment >= iter) << std::endl;
	// while(iter != vect.end())
	// 	std::cout << *(iter++)<< std::endl;
	// std::cout << "Testing with a struct!" << std::endl;
	// std::vector<data>			Data;
	// Data.push_back(data(10, 20));
	// Data.push_back(data(100, 200));
	// Data.push_back(data(1000, 2000));
	// Data.push_back(data(10000, 20000));
	// Data.push_back(data(100000, 2000000));
	// Data.push_back(data(1000000, 20000000));
	// Data.push_back(data(10000000, 20000000));
	// std::vector<data>::iterator dataIterator(Data.begin());
	// std::vector<data>::iterator	dataAssignment(dataIterator);
	// std::cout << dataIterator->a << std::endl;
	// std::cout << dataIterator->b << std::endl;
    // std::cout << (dataIterator == dataAssignment) << std::endl;
	// std::cout << (dataIterator != dataAssignment) << std::endl;
	// std::cout << (dataIterator < dataAssignment) << std::endl;
	// std::cout << (dataIterator <= dataAssignment) << std::endl;
	// std::cout << (dataIterator > dataAssignment) << std::endl;
	// std::cout << (dataIterator >= dataAssignment) << std::endl;
	// std::cout << dataIterator[2].a << std::endl;
	// std::cout << "Testing reverse iterator!" << std::endl;
    // std::vector<int> 			bvect;
	// bvect.push_back(1337);
	// bvect.push_back(42);
	// bvect.push_back(23);
	// bvect.push_back(6);
	// bvect.push_back(1997);
	// std::vector<int>::reverse_iterator	biter(bvect.end());
	// std::cout << biter[2] << std::endl;
	// biter--;
	// std::cout << *biter << std::endl;
	// biter--;
	// std::cout << *biter << std::endl;
	// std::cout << *(biter.base()) << std::endl;
	// std::cout << *(++biter) << std::endl;
	// std::cout << *(--biter) << std::endl;
	// std::cout << *(biter++) << std::endl;
	// std::cout << *(biter--) << std::endl;
	// std::cout << *(biter - 2) << std::endl;
	// std::cout << *(biter) << std::endl;
	// std::cout << *(biter + 2) << std::endl;
	// std::vector<int>::reverse_iterator	biterAssignment(biter);
	// biterAssignment += 3;
	// std::cout << *biterAssignment << std::endl;
	// biterAssignment -= 3;
	// std::cout << *biterAssignment << std::endl;
	// std::cout << biter[2] << std::endl;
	// std::cout << (biterAssignment == biter) << std::endl;
	// biterAssignment += 1;
	// std::cout << (biterAssignment == biter) << std::endl;
	// std::cout << (biterAssignment != biter) << std::endl;
	// std::cout << (biterAssignment < biter) << std::endl;
	// std::cout << (biterAssignment <= biter) << std::endl;
	// std::cout << (biterAssignment > biter) << std::endl;
	// std::cout << (biterAssignment >= biter) << std::endl;
	// std::cout << "Testing reverse iterator! with the data" << std::endl;
	// std::vector<data>::reverse_iterator revIteratorData(Data.end());
	// std::cout << revIteratorData->a << std::endl;
	// std::cout << revIteratorData->b << std::endl;
	// revIteratorData++;
	// std::cout << revIteratorData->a << std::endl;
	// std::cout << revIteratorData->b << std::endl;
	// ++revIteratorData;
	// std::cout << revIteratorData->a << std::endl;
	// std::cout << revIteratorData->b << std::endl;
	// std::vector<data>::reverse_iterator revbis(revIteratorData);
	// std::cout << (revIteratorData == revbis) << std::endl;
	// std::cout << (revIteratorData != revbis) << std::endl;
	// std::cout << (revIteratorData < revbis) << std::endl;
	// std::cout << (revIteratorData <= revbis) << std::endl;
	// std::cout << (revIteratorData > revbis) << std::endl;
	// std::cout << (revIteratorData >= revbis) << std::endl;
	// std::cout << revIteratorData[2].a << std::endl;
	// std::cout << revbis[2].a << std::endl;
	// std::cout << (revbis.base())[0].a << std::endl;
	// std::cout << "Testing the iterators Functions" << std::endl;
	// std::vector<data>::iterator it(Data.begin());
	// std::cout << it->a << std::endl;
	// it = Data.end();
	// std::cout << it->a << std::endl;
	// std::vector<data>::reverse_iterator it2(Data.rbegin());
	// std::cout << it2->a << std::endl;
	// std::vector<data>::reverse_iterator it3(Data.begin());
	// std::cout << it3->a << std::endl;
	// it2 = Data.rend();
	// std::cout << it2->a << std::endl;
	// std::vector<data>::reverse_iterator it4(Data.end());
	// std::cout << it4->a << std::endl;
	std::vector<data> emptyData;
	// std::vector<data>::reverse_iterator emptyDataRevIt(emptyData.begin());
	// emptyDataRevIt = emptyData.rend();
	std::cout << "Testing Capacity functions" << std::endl;
	std::cout << emptyData.capacity()  << std::endl;
	std::cout << emptyData.size() << std::endl;
	std::cout << emptyData.max_size() << std::endl;
	data tab(1337, 42);
	emptyData.resize(3, tab);
	std::vector<data>::iterator iterTest(emptyData.begin());
	std::cout << iterTest[0].a << std::endl;
	std::cout << iterTest[1].a << std::endl;
	std::cout << iterTest[2].a << std::endl;
	std::cout << emptyData.capacity() << std::endl;
	std::cout << emptyData.size() << std::endl;
	std::cout << emptyData.max_size() << std::endl;
	emptyData.resize(8, tab);
	std::cout << iterTest[0].a << std::endl;
	std::cout << iterTest[1].a << std::endl;
	std::cout << iterTest[2].a << std::endl;
	std::cout << emptyData.capacity() << std::endl;
	std::cout << emptyData.size() << std::endl;
	std::cout << emptyData.max_size() << std::endl;
}