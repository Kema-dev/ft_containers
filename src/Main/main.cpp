#include <iostream>
#include <string>

#if false
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../Map/Map.hpp"
	#include "../Vector/Vector.hpp"
	#include "../Stack/Stack.hpp"
	#include "../Set/Set.hpp"
	#include "../Tools/Utils.hpp"
#endif

int main(void)
{
    //SECTION VECTOR TESTS
    
	//SECTION pop_back()
	ft::vector<int> v;
    v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
    for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
    v.pop_back();
    for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";

	//!SECTION
    std::cout << std::endl;

	//SECTION swap()
    ft::vector<int> foo (3,100);
    ft::vector<int> bar (5,200);
    ft::vector<int> baz (bar.begin(), bar.end());
    foo.swap(bar);
    std::cout << "baz contains:";
    for (unsigned i=0; i<baz.size(); i++)
        std::cout << ' ' << baz[i];
    std::cout << std::endl;
    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << std::endl; 
	//!SECTION

	//SECTION constructors
	ft::vector<int> first;
	ft::vector<int> second (4,100);
	std::cout << "second contains:";
    for (unsigned i=0; i<second.size(); i++)
        std::cout << ' ' << second[i];
    std::cout << std::endl; 
	ft::vector<int> third (second.begin(),second.end());
	std::cout << "third contains:";
    for (unsigned i=0; i<third.size(); i++)
        std::cout << ' ' << third[i];
    std::cout << std::endl;
	ft::vector<int> fourth (third); 
	std::cout << "fourth contains:";
    for (unsigned i=0; i<fourth.size(); i++)
        std::cout << ' ' << fourth[i];
    std::cout << std::endl;
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "fifth contains:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	//SECTION

	//SECTION reverse iterators
	ft::vector<int> myvector (5);
	int i=0;
	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit != myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	//!SECTION
	std::cout << std::endl;

	//SECTION size() capacity() max_size()
	ft::vector<int> myhector;
  // set some content in the vector:
	for (int i=0; i<100; i++) myhector.push_back(i);
	std::cout << "size: " << myhector.size() << "\n";
	std::cout << "capacity: " << myhector.capacity() << "\n";
	std::cout << "max_size: " << myhector.max_size() << "\n";
	//!SECTION

	//SECTION empty()
	ft::vector<int> myrector;
	int sum (0);
	for (int i=1;i<=10;i++) myrector.push_back(i);
	while (!myrector.empty())
	{
		sum += myrector.back();
		myrector.pop_back();
	}
	std::cout << "total: " << sum << std::endl;
	//!SECTION

	//SECTION reserve()
	ft::vector<int>::size_type sz;
	ft::vector<int> fou;
	sz = fou.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		fou.push_back(i);
		if (sz!=fou.capacity()) {
		sz = fou.capacity();
		std::cout << "capacity changed: " << sz << std::endl;
		}
	}
	ft::vector<int> bor;
	sz = bor.capacity();
	bor.reserve(100);
	std::cout << "making bor grow:\n";
	for (int i=0; i<100; ++i) {
		bor.push_back(i);
		if (sz!=bor.capacity()) {
		sz = bor.capacity();
		std::cout << "capacity changed: " << sz << std::endl;
		}
	}
	//!SECTION

	//SECTION at()
	ft::vector<int> mylector (10);
	for (unsigned i=0; i<mylector.size(); i++)
		mylector.at(i)=i;
	std::cout << "mylector contains:";
	for (unsigned i=0; i<mylector.size(); i++)
		std::cout << ' ' << mylector.at(i);
	std::cout << std::endl;
  	//!SECTION

	//SECTION front() back()
	ft::vector<int> mypector;
	mypector.push_back(78);
	mypector.push_back(16);
	mypector.front() -= mypector.back();
	std::cout << "mypector.front() is now " << mypector.front() << std::endl;
	//!SECTION

	//SECTION assign()
	ft::vector<int> six;
	ft::vector<int> seven;
	ft::vector<int> eight;
	six.assign (7,100);             // 7 ints with a value of 100
	ft::vector<int>::iterator ite;
	ite=six.begin()+1;
	seven.assign (ite,six.end()-1); // the 5 central values of six
	int ints[] = {1776,7,4};
	eight.assign (ints,ints+3);   // assigning from array.
	std::cout << "Size of six: " << int (six.size()) << std::endl;
	std::cout << "Size of seven: " << int (seven.size()) << std::endl;
	std::cout << "Size of eight: " << int (eight.size()) << std::endl;
	//!SECTION

	//SECTION insert() erase()
	ft::vector<int> vector_test (3,100);
	ft::vector<int>::iterator iter;
	
	iter = vector_test.begin();
	for (iter=vector_test.begin(); iter<vector_test.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << std::endl;

	iter = vector_test.begin();
	iter = vector_test.insert ( iter , 200 );
	for (iter=vector_test.begin(); iter<vector_test.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << std::endl;

	iter = vector_test.begin();
	vector_test.insert (iter,2,300);
	for (iter=vector_test.begin(); iter<vector_test.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << std::endl;

	iter = vector_test.begin();
	ft::vector<int> anothervector (2,400);
	vector_test.insert (iter,anothervector.begin(),anothervector.end());
	for (iter=vector_test.begin(); iter<vector_test.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << std::endl;

	int myarray [] = { 501,502,503 };
	vector_test.insert (vector_test.begin(), myarray, myarray+3);
	std::cout << "vector_test contains:";
	for (iter=vector_test.begin(); iter<vector_test.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << std::endl;
	//!SECTION

	//!SECTION get_allocator()
	ft::vector<int> myfector;
	int * p;
	unsigned int k;
	p = myfector.get_allocator().allocate(5);
	for (k=0; k<5; k++) myfector.get_allocator().construct(&p[k],k);
	std::cout << "The allocated array contains:";
	for (k=0; k<5; k++) std::cout << ' ' << p[k];
	std::cout << std::endl;
	for (k=0; k<5; k++) myfector.get_allocator().destroy(&p[k]);
	myfector.get_allocator().deallocate(p,5);
	//!SECTION

    //!SECTION VECTOR TESTS
    return (0);
}