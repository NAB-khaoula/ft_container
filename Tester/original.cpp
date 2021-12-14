#include <vector>
#include <stack>
#include <map>
#include <iterator>
#include <iostream>

typedef struct data
{
	int a;
	int b;
	// data() {std::cout << "Constructor Default\n";}
	data(int a = 1337, int b = 42) : a(a), b(b)
	{
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "Constructor parametrse\n";
	}
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
} t_data;

int main()
{
	std::cout << "*************************************************************************" << std::endl;
    std::cout << "\t\t\t\tVECTOR" << std::endl;
    std::cout << "*************************************************************************" << std::endl;

	// NOTE - Constructor
	{
		std::vector<int> first;                                
		std::vector<int> second (4,100);                      
		std::vector<int> third (second.begin(),second.end()); 
		std::vector<int> fourth (third);                       
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// NOTE - Assign content (operator=)
	{
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);
		bar = foo;
		foo = std::vector<int>();
		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}

	// NOTE - Return iterator to beginning
	{
		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	
	// NOTE - Return iterator to end
	{

		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	
	// NOTE - Return reverse iterator to reverse beginning
	{
		std::vector<int> myvector (5);  // 5 default-constructed ints
		int i=0;
		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	
	// NOTE - Return reverse iterator to reverse end
	{
		std::vector<int> myvector (5); 
		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	
	// NOTE - Return size
	{
		std::vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';
		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';
		myints.insert (myints.end(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';
		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}
	
	// NOTE - Return maximum size

	{
		std::vector<int> myvector;
		for (int i=0; i<100; i++) myvector.push_back(i);
		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n"; 
	}
	
	// NOTE - Change size
	{
		std::vector<int> myvector;
		for (size_t i=1;i<10;i++) myvector.push_back(i);
		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		myvector.resize(30, 60);
		myvector.resize(15, 60);
		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	
	// NOTE - Return size of allocated storage capacity
	{
		std::vector<int> myvector;
		for (int i=0; i<100; i++) myvector.push_back(i);
		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	
	// NOTE - Test whether vector is empty
	{
		std::vector<int> myvector;
		int sum (0);
		for (int i=1;i<=10;i++) myvector.push_back(i);
		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		std::cout << "total: " << sum << '\n';
	}
	
	// NOTE - Request a change in capacity
	{
		std::vector<int>::size_type sz;
		std::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
	
	// NOTE - Access element
	{
		std::vector<int> myvector (10);
		std::vector<int>::size_type sz = myvector.size();
		for (unsigned i=0; i<sz; i++) myvector[i]=i;
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}
		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	
	// NOTE - Access element
	{
		std::vector<int> myvector (10);
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}

	// NOTE - Access first element
	{
		std::vector<int> myvector;
		myvector.push_back(78);
		myvector.push_back(16);
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	
	// NOTE - Access last element
	{
		std::vector<int> myvector;
		myvector.push_back(10);
		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	
	// NOTE - Assign vector content
	{
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;
		first.assign (7,100);          
		std::vector<int>::iterator it;
		it=first.begin()+1;
		second.assign (it,first.end()-1);
		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);
		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	
	// NOTE - Delete last element
	{
		std::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);
		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		std::cout << "The elements of myvector add up to " << sum << '\n';
	}
	
	// NOTE - Clear content
	{
		std::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		std::cout << myvector.size() << std::endl;
		std::cout << myvector.capacity() << std::endl;
		myvector.clear();
		std::cout << myvector.size() << std::endl;
		std::cout << myvector.capacity() << std::endl;
		myvector.push_back (1101);
		myvector.push_back (2202);
		std::cout << myvector.size() << std::endl;
		std::cout << myvector.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	
	// NOTE - Insert elements
	{    
		std::vector<int> myvector(3, 100);
		std::cout << myvector.size() << std::endl;
		std::cout << myvector.capacity() << std::endl;
		std::vector<int>::iterator it;
		it = myvector.begin();
		it = myvector.insert ( it , 200 );
		myvector.insert (it,2,300);
		it = myvector.begin();
		std::vector<int> anothervector (2,400);
		std::cout << myvector.size() << std::endl;
		std::cout << myvector.capacity() << std::endl;
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		std::cout << myvector.size() << std::endl;
		std::cout << myvector.capacity() << std::endl;
		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		it = vec.insert(vec.begin(), 3);
		vec.insert(it, 2);
		int i = 2;
		it = vec.insert(vec.begin() + i, 7);
		std::cout << "The vector elements are: ";
		for (std::vector<int>::iterator it1 = vec.begin(); it1 != vec.end(); ++it1)
			std::cout << *it1 << " ";
		std::cout << '\n';
	}
	
	// NOTE - Erase elements
	{
		std::vector<int> myvector1;
		for (int i=1; i<=10; i++) myvector1.push_back(i);
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		myvector1.erase (myvector1.begin() - 1);
		myvector1.erase (myvector1.begin(),myvector1.begin()+3);
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); ++i)
			std::cout << ' ' << myvector1[i];
		std::cout << std::endl;
	}

	// NOTE - Swap content
	{ 
		std::vector<int> foo(3, 100);   // three ints with a value of 100
		std::vector<int> bar(5, 200);   // five ints with a value of 200
		std::cout << "Size foo before " << foo.size() << std::endl;
		std::cout << "Capa foo before " << foo.capacity() << std::endl;
		std::cout << "Size bar before " << bar.size() << std::endl;
		std::cout << "Capa bar before " << bar.capacity() << std::endl;
		foo.swap(bar);
		std::cout << "Size foo after " << foo.size() << std::endl;
		std::cout << "Capa foo after " << foo.capacity() << std::endl;
		std::cout << "Size bar after " << bar.size() << std::endl;
		std::cout << "Capa bar after " << bar.capacity() << std::endl;
		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';
		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
	}

	// NOTE - Get allocator
	{
		std::vector<int> myvector;
		int * p;
		unsigned int i;
		p = myvector.get_allocator().allocate(5);
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}
	//    NOTE - Relational operators for vector
	{
		std::vector<int> foo (1,200);   // three ints with a value of 100
		std::vector<int> bar (1,100);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	
	// NOTE - Exchange contents of vectors
	{
		std::vector<int> foo(3,100);   // three ints with a value of 100
		std::vector<int> bar(5,200);   // five ints with a value of 200
		std::swap(foo, bar);
		std::cout << "foo contains:";
		for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "bar contains:";
		for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	std::cout << "*************************************************************************" << std::endl;
    std::cout << "\t\t\t\tSTACK" << std::endl;
    std::cout << "*************************************************************************" << std::endl;

	// NOTE - std::stack::stack
	{
		std::vector<int> myvector (2,200);        // vector with 2 elements
		std::stack<int> first;                    // empty stack
		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);
		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	// NOTE - std::stack::empty
	{
		std::stack<int> mystack;
		int sum (0);
		for (int i=1;i<=10;i++) mystack.push(i);
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}

	// NOTE - std::stack::size
	{
		std::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';
		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';
		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	// NOTE - std::stack::top
		std::stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		std::cout << "mystack.top() is now " << mystack.top() << '\n';

	// NOTE - std::stack::push
	{
		std::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}

	// NOTE - std::stack::pop
	{
		std::stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}

	// NOTE - operator==
	{
		std::stack <int, std::vector<int> > s1, s2, s3;
		s1.push( 1 );
		s2.push( 2 );
		s3.push( 1 );
		if ( s1 == s2 )
			std::cout << "The stacks s1 and s2 are equal." << std::endl;
		else
			std::cout << "The stacks s1 and s2 are not equal." << std::endl;

		if ( s1 == s3 )
			std::cout << "The stacks s1 and s3 are equal." << std::endl;
		else
			std::cout << "The stacks s1 and s3 are not equal." << std::endl;
	}

	// NOTE - operator!=
	{
		std::stack <int, std::vector<int> > s1, s2, s3;
		s1.push( 1 );
		s2.push( 2 );
		s3.push( 1 );
		if ( s1 != s2 )
			std::cout << "The stacks s1 and s2 are not equal." << std::endl;
		else
			std::cout << "The stacks s1 and s2 are equal." << std::endl;
		if ( s1 != s3 )
			std::cout << "The stacks s1 and s3 are not equal." << std::endl;
		else
			std::cout << "The stacks s1 and s3 are equal." << std::endl;
	}

	// NOTE - operator<
	{
		std::stack <int, std::vector<int> > s1, s2, s3;
		s1.push( 2 );
		s1.push( 4 );
		s1.push( 6 );
		s1.push( 8 );
		s2.push( 5 );
		s2.push( 10 );
		s3.push( 2 );
		s3.push( 4 );
		s3.push( 6 );
		s3.push( 8 );
		if ( s1 < s2 )
			std::cout << "The stack s1 is less than "
				<< "the stack s2." << std::endl;
		else
			std::cout << "The stack s1 is greater than or equal to "
				<< "the stack s2." << std::endl;

		if ( s1 < s3 )
			std::cout << "The stack s1 is less than "
				<< "the stack s3." << std::endl;
		else
			std::cout << "The stack s1 is greater than to "
				<< "the stack s3." << std::endl;
		std::stack <int>::size_type i_size_s1 = s1.size( );
		std::cout << "The stack s1 from the top down is: ( ";
		unsigned int i;
		for ( i = 1 ; i <= i_size_s1 ; i++ )
		{
			std::cout << s1.top( ) << " ";
			s1.pop( );
		}
		std::cout << ")." << std::endl;
	}

	// NOTE - operator<=
	{
		std::stack <int> s1, s2, s3;
		s1.push( 5 );
		s1.push( 10 );
		s2.push( 1 );
		s2.push( 2 );
		s3.push( 5 );
		s3.push( 10 );
		if ( s1 <= s2 )
			std::cout << "The stack s1 is less than or equal to "
				<< "the stack s2." << std::endl;
		else
			std::cout << "The stack s1 is greater than "
				<< "the stack s2." << std::endl;

		if ( s1 <= s3 )
			std::cout << "The stack s1 is less than or equal to "
				<< "the stack s3." << std::endl;
		else
			std::cout << "The stack s1 is greater than "
				<< "the stack s3." << std::endl;
	}

	// NOTE - operator>
	{
		std::stack <int, std::vector<int> > s1, s2, s3;
		s1.push( 1 );
		s1.push( 2 );
		s1.push( 3 );
		s2.push( 5 );
		s2.push( 10 );
		s3.push( 1 );
		s3.push( 2 );
		if ( s1 > s2 )
			std::cout << "The stack s1 is greater than "
				<< "the stack s2." << std::endl;
		else
			std::cout << "The stack s1 is not greater than "
				<< "the stack s2." << std::endl;

		if ( s1 > s3 )
			std::cout << "The stack s1 is greater than "
				<< "the stack s3." << std::endl;
		else
			std::cout << "The stack s1 is not greater than "
				<< "the stack s3." << std::endl;
	}

	// NOTE - operator>=
	{
		std::stack <int, std::vector<int> > s1, s2, s3;
		s1.push( 1 );
		s1.push( 2 );
		s2.push( 5 );
		s2.push( 10 );
		s3.push( 1 );
		s3.push( 2 );
		if ( s1 >= s2 )
			std::cout << "The stack s1 is greater than or equal to "
				<< "the stack s2." << std::endl;
		else
			std::cout << "The stack s1 is less than "
				<< "the stack s2." << std::endl;

		if ( s1>= s3 )
			std::cout << "The stack s1 is greater than or equal to "
				<< "the stack s3." << std::endl;
		else
			std::cout << "The stack s1 is less than "
				<< "the stack s3." << std::endl;
	}
	//NOTE:

	 std::cout << "*************************************************************************" << std::endl;
    std::cout << "\t\t\t\tMap" << std::endl;
    std::cout << "*************************************************************************" << std::endl;

    // NOTE - Construct pair
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::pair<std::string, double> product1;
        std::pair<std::string, double> product2("tomatoes", 2.30);
        std::pair<std::string, double> product3(product2);
        product1 = std::make_pair(std::string("lightbulbs"), 0.99); // using make_pair (move)
        product2.first = "shoes";
        product2.second = 39.90;
        std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    }

    // NOTE - pair::operator= example
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::pair<std::string, int> planet("Earth", 6371), homeplanet;
        planet = std::make_pair("Earth", 6371);
        homeplanet = planet;
        std::cout << "Home planet: " << homeplanet.first << '\n';
        std::cout << "Planet size: " << homeplanet.second << '\n';
    }

    // NOTE - make_pair example
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::pair<int, int> foo;
        std::pair<int, int> bar;
        foo = std::make_pair(10, 20);
        bar = std::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>
        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    }

    // NOTE - Relational operators for pair
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::pair<int, char> foo(10, 'z');
        std::pair<int, char> bar(90, 'a');
        if (foo == bar)
            std::cout << "foo and bar are equal\n";
        if (foo != bar)
            std::cout << "foo and bar are not equal\n";
        if (foo < bar)
            std::cout << "foo is less than bar\n";
        if (foo > bar)
            std::cout << "foo is greater than bar\n";
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar\n";
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar\n";
    }

    // NOTE - Construct map
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> first;
        first['a'] = 10;
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;
        std::map<char, int> second(first.begin(), first.end());
        for (std::map<char, int>::iterator i = second.begin(); i != second.end(); i++)
            std::cout << i->first << "\t" << i->second << std::endl;
    }

    // // NOTE - Access element
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, std::string> mymap;
        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];
        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';
        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }

    // // NOTE - Test whether container is empty
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }

    // // NOTE - Return maximum size
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        int i;
        std::map<int, int> mymap;
        if (mymap.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
                mymap[i] = i;
            std::cout << "The map contains 1000 elements.\n";
        }
        std::cout << mymap.max_size() << std::endl;
    }

    // // NOTE - Insert elements
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        // first insert function version (single parameter):
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));
        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
        std::cout << mymap.size() << std::endl;
        // second insert function version (with hint position):
        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, std::pair<char, int>('c', 400));
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.end());
        for (std::map<char, int>::iterator i = anothermap.begin(); i != anothermap.end(); i++)
        {
            std::cout << i->first << "\t" << i->second << std::endl;
        }
    }

    // // NOTE - Clear content
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;
        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;
        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    // // NOTE - Assignement Operator (new_map = old_map)
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> first;
        std::map<char, int> second;
        first['x'] = 8;
        first['y'] = 16;
        first['z'] = 32;
        second = first;               // second now contains 3 ints
        first = std::map<char, int>(); // and first is now empty
        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }

    // NOTE - Erase elements
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<int, int> mymap;
        // insert some values:
        mymap[10] = 10;
        mymap[20] = 20;
        mymap[30] = 30;
        mymap[40] = 40;
        mymap[50] = 50;
        mymap[60] = 60;
        std::map<int, int>::iterator it = mymap.begin();
        it = mymap.find(20);
        mymap.erase(it);  // erasing by iterator
        mymap.erase(30); // erasing by key
        it = mymap.find(50);
        mymap.erase(it, mymap.end()); // erasing by range
        // show content:
        for (it = mymap.begin(); it != mymap.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << '\n';
        }
    }

    // NOTE - Swap content
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> foo, bar;
        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;
        foo.swap(bar);
        std::cout << "foo contains:\n";
        for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << '\n';
        }
        std::cout << "bar contains:\n";
        for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    // NOTE - Return key comparison object
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;
        std::cout << "mymap contains:\n";
        char highest = mymap.rbegin()->first; // key value of last element
        std::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.key_comp()((*it++).first, highest));
        std::cout << '\n';
    }

    // NOTE - Return value comparison object
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int, std::greater<char> > mymap;
        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;
        std::cout << "mymap contains:\n";
        std::pair<char, int> highest = *mymap.rbegin(); // last element
        std::map<char, int, std::greater<char> >::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }

    // NOTE - Get iterator to element
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;
        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;
        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);
        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }

    // NOTE - Count elements with a specific key
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        char c;
        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;
        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }

    // NOTE - Return iterator to lower bound
    // NOTE - Return iterator to upper bound
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;
        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;
        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)
		
        mymap.erase(itlow, itup);       // erases [itlow,itup)
        // print content:
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    // NOTE - Get range of equal elements
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        std::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }

    // NOTE - Get allocator
    {
        std::cout << "------------- Library FT -------------" << std::endl;
        int psize;
        std::map<char, int> mymap;
        std::pair<const char, int> *p;
        // allocate an array of 5 elements using mymap's allocator:
        p = mymap.get_allocator().allocate(5);
        // assign some values to array
        psize = sizeof(std::map<char, int>::value_type) * 5;
        std::cout << "The allocated array has a size of " << psize << " bytes.\n";
        mymap.get_allocator().deallocate(p, 5);

        std::map<int, std::string> m;
        m.insert(std::make_pair(1, "mojahid"));
        m.insert(std::make_pair(2, "yassir"));
        m.insert(std::make_pair(3, "zakaria"));
        std::map<int, std::string>::iterator it = m.begin();
        m[3] = "khaoula";
        for (; it != m.end(); it++)
        {
            std::cout << it->first << "\t" << it->second << std::endl;
        }
    }

	//NOTE - create 10000 map 
	{
		std::map<int,int> mymap;
		for(size_t i = 0 ; i< 10000  ; i++)
			mymap[i] = i;
		mymap.erase(mymap.begin(), mymap.end());
	}

}	
