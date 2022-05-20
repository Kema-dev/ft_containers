#include <iostream>
#include <string>

// INFO true = std / false = ft
#if false
#include <map>
#include <stack>
#include <vector>
#include <set>
namespace ft = std;
#else
#include "../Map/Map.hpp"
#include "../Set/Set.hpp"
#include "../Stack/Stack.hpp"
#include "../Tools/Utils.hpp"
#include "../Vector/Vector.hpp"
#endif

int intcmp(int int1, int int2) {
	return ((int1 > int2) ? int1 : int2);
}

struct classcomp {
	bool operator()(const char& lhs, const char& rhs) const {
		return lhs < rhs;
	}
};

int main(void) {
	// {
	// 	// SECTION VECTOR TESTS
	// 	std::cout << "------------------------------------------" << std::endl;
	// 	std::cout << "---------------VECTOR TESTS---------------" << std::endl;
	// 	std::cout << "------------------------------------------" << std::endl;
	// 	std::cout << std::endl;
	// 	{
	// 		// SECTION pop_back()
	// 		std::cout << "----------TESTING pop_back()----------" << std::endl;
	// 		ft::vector<int> MyVector_1;
	// 		MyVector_1.push_back(1);
	// 		MyVector_1.push_back(2);
	// 		MyVector_1.push_back(3);
	// 		MyVector_1.push_back(4);
	// 		MyVector_1.push_back(5);
	// 		std::cout << "MyVector_1: ";
	// 		for (ft::vector<int>::iterator it = MyVector_1.begin(); it != MyVector_1.end(); ++it)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;
	// 		MyVector_1.pop_back();
	// 		std::cout << "MyVector_1 should contain: 1 2 3 4" << std::endl;
	// 		std::cout << "MyVector_1 after pop_back(): ";
	// 		for (ft::vector<int>::iterator it = MyVector_1.begin(); it != MyVector_1.end(); ++it)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION swap()
	// 		std::cout << "----------TESTING swap() operator[]----------" << std::endl;
	// 		ft::vector<int> MyVector_2(3, 100);
	// 		ft::vector<int> MyVector_3(5, 200);
	// 		std::cout << "MyVector_2 contains: ";
	// 		for (ft::vector<int>::iterator it = MyVector_2.begin(); it != MyVector_2.end(); ++it)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "MyVector_3 contains: ";
	// 		for (ft::vector<int>::iterator it = MyVector_3.begin(); it != MyVector_3.end(); ++it)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "Swapping MyVector_2 and MyVector_3" << std::endl;
	// 		MyVector_2.swap(MyVector_3);
	// 		std::cout << "MyVector_2 contains:";
	// 		for (unsigned i = 0; i < MyVector_2.size(); i++)
	// 			std::cout << ' ' << MyVector_2[i];
	// 		std::cout << std::endl;
	// 		std::cout << "MyVector_3 contains:";
	// 		for (unsigned i = 0; i < MyVector_3.size(); i++)
	// 			std::cout << ' ' << MyVector_3[i];
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION constructors
	// 		std::cout << "----------TESTING constructors----------" << std::endl;
	// 		ft::vector<int> MyVector_4;
	// 		ft::vector<int> MyVector_5(4, 100);
	// 		std::cout << "MyVector_5 should contain: 100 100 100 100" << std::endl;
	// 		std::cout << "MyVector_5 contains:";
	// 		for (unsigned i = 0; i < MyVector_5.size(); i++)
	// 			std::cout << ' ' << MyVector_5[i];
	// 		std::cout << std::endl;
	// 		ft::vector<int> MyVector_6(MyVector_5.begin(), MyVector_5.end());
	// 		std::cout << "MyVector_6 should contain: 100 100 100 100" << std::endl;
	// 		std::cout << "MyVector_6 contains:";
	// 		for (unsigned i = 0; i < MyVector_6.size(); i++)
	// 			std::cout << ' ' << MyVector_6[i];
	// 		std::cout << std::endl;
	// 		std::cout << "MyVector_7 should contain: 100 100 100 100" << std::endl;
	// 		ft::vector<int> MyVector_7(MyVector_6);
	// 		std::cout << "MyVector_7 contains:";
	// 		for (unsigned i = 0; i < MyVector_7.size(); i++)
	// 			std::cout << ' ' << MyVector_7[i];
	// 		std::cout << std::endl;
	// 		int myints[] = {16, 2, 77, 29};
	// 		ft::vector<int> MyVector_8(myints, myints + sizeof(myints) / sizeof(int));
	// 		std::cout << "MyVector_8 should contain: 16 2 77 29" << std::endl;
	// 		std::cout << "MyVector_8 contains:";
	// 		for (ft::vector<int>::iterator it = MyVector_8.begin(); it != MyVector_8.end(); ++it)
	// 			std::cout << ' ' << *it;
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION reverse iterators
	// 		std::cout << "----------TESTING reverse iterators----------" << std::endl;
	// 		ft::vector<int> MyVector_9(5);
	// 		int i = 0;
	// 		ft::vector<int>::reverse_iterator rit = MyVector_9.rbegin();
	// 		for (; rit != MyVector_9.rend(); ++rit)
	// 			*rit = ++i;
	// 		std::cout << "MyVector_9 should contain: 5 4 3 2 1" << std::endl;
	// 		std::cout << "MyVector_9 contains:";
	// 		for (ft::vector<int>::iterator it = MyVector_9.begin(); it != MyVector_9.end(); ++it)
	// 			std::cout << ' ' << *it;
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION size() capacity() max_size()
	// 		std::cout << "----------TESTING size() capacity() max_size()----------" << std::endl;
	// 		ft::vector<int> MyVector_10;
	// 		for (int i = 0; i < 100; i++) MyVector_10.push_back(i);
	// 		std::cout << "MyVector_10 size: " << MyVector_10.size() << "\n";
	// 		std::cout << "MyVector_10 capacity: " << MyVector_10.capacity() << "\n";
	// 		std::cout << "MyVector_10 max_size: " << MyVector_10.max_size() << "\n";
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION empty()
	// 		std::cout << "----------TESTING empty()----------" << std::endl;
	// 		ft::vector<int> MyVector_11;
	// 		int sum(0);
	// 		for (int i = 1; i <= 10; i++) MyVector_11.push_back(i);
	// 		while (!MyVector_11.empty()) {
	// 			sum += MyVector_11.back();
	// 			MyVector_11.pop_back();
	// 		}
	// 		std::cout << "MyVector_11 total: " << sum << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION reserve()
	// 		std::cout << "----------TESTING reserve()----------" << std::endl;
	// 		ft::vector<int>::size_type sz;
	// 		ft::vector<int> MyVector_12;
	// 		sz = MyVector_12.capacity();
	// 		std::cout << "Making MyVector_12 grow:" << std::endl;
	// 		for (int i = 0; i < 100; ++i) {
	// 			MyVector_12.push_back(i);
	// 			if (sz != MyVector_12.capacity()) {
	// 				sz = MyVector_12.capacity();
	// 				std::cout << "MyVector_12 capacity changed: " << sz << std::endl;
	// 			}
	// 		}
	// 		ft::vector<int> MyVector_13;
	// 		sz = MyVector_13.capacity();
	// 		MyVector_13.reserve(100);
	// 		std::cout << "Making MyVector_13 grow:" << std::endl;
	// 		for (int i = 0; i < 100; ++i) {
	// 			MyVector_13.push_back(i);
	// 			if (sz != MyVector_13.capacity()) {
	// 				sz = MyVector_13.capacity();
	// 				std::cout << "MyVector_13 capacity changed: " << sz << std::endl;
	// 			}
	// 		}
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION at()
	// 		std::cout << "----------TESTING at()----------" << std::endl;
	// 		ft::vector<int> MyVector_14(10);
	// 		for (unsigned i = 0; i < MyVector_14.size(); i++)
	// 			MyVector_14.at(i) = i;
	// 		std::cout << "MyVector_14 contains:";
	// 		for (unsigned i = 0; i < MyVector_14.size(); i++)
	// 			std::cout << ' ' << MyVector_14.at(i);
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION front() back()
	// 		std::cout << "----------TESTING front() back()----------" << std::endl;
	// 		ft::vector<int> MyVector_15;
	// 		MyVector_15.push_back(78);
	// 		MyVector_15.push_back(16);
	// 		std::cout << "Front of MyVector_15: " << MyVector_15.front() << std::endl;
	// 		std::cout << "Back of MyVector_15: " << MyVector_15.back() << std::endl;
	// 		std::cout << "Front of MyVector_15 should be 62 (78-16)" << std::endl;
	// 		MyVector_15.front() -= MyVector_15.back();
	// 		std::cout << "Front of MyVector_15 is now " << MyVector_15.front() << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION assign()
	// 		std::cout << "----------TESTING assign()----------" << std::endl;
	// 		ft::vector<int> MyVector_16;
	// 		ft::vector<int> MyVector_17;
	// 		ft::vector<int> MyVector_18;
	// 		MyVector_16.assign(7, 100);
	// 		ft::vector<int>::iterator ite;
	// 		ite = MyVector_16.begin() + 1;
	// 		MyVector_17.assign(ite, MyVector_16.end() - 1);
	// 		int ints[] = {1776, 7, 4};
	// 		MyVector_18.assign(ints, ints + 3);
	// 		std::cout << "Size of MyVector_16: " << int(MyVector_16.size()) << std::endl;
	// 		std::cout << "Size of MyVector_17: " << int(MyVector_17.size()) << std::endl;
	// 		std::cout << "Size of MyVector_18: " << int(MyVector_18.size()) << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION insert() erase()
	// 		std::cout << "----------TESTING insert() erase()----------" << std::endl;
	// 		ft::vector<int> MyVector_19(3, 100);
	// 		ft::vector<int>::iterator iter;

	// 		iter = MyVector_19.begin();
	// 		std::cout << "MyVector_19 contains:";
	// 		for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
	// 			std::cout << ' ' << *iter;
	// 		std::cout << std::endl;

	// 		iter = MyVector_19.begin();
	// 		iter = MyVector_19.insert(iter, 200);
	// 		std::cout << "MyVector_19 contains:";
	// 		for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
	// 			std::cout << ' ' << *iter;
	// 		std::cout << std::endl;

	// 		iter = MyVector_19.begin();
	// 		MyVector_19.insert(iter, 2, 300);
	// 		std::cout << "MyVector_19 contains:";
	// 		for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
	// 			std::cout << ' ' << *iter;
	// 		std::cout << std::endl;

	// 		iter = MyVector_19.begin();
	// 		ft::vector<int> MyVector_20(2, 400);
	// 		MyVector_19.insert(iter, MyVector_20.begin(), MyVector_20.end());
	// 		std::cout << "MyVector_19 contains:";
	// 		for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
	// 			std::cout << ' ' << *iter;
	// 		std::cout << std::endl;

	// 		int myarray[] = {501, 502, 503};
	// 		MyVector_19.insert(MyVector_19.begin(), myarray, myarray + 3);
	// 		std::cout << "MyVector_19 contains:";
	// 		for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
	// 			std::cout << ' ' << *iter;
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION clear()
	// 		std::cout << "----------TESTING clear()----------" << std::endl;
	// 		ft::vector<int> MyVector_21;
	// 		MyVector_21.push_back(12332300);
	// 		MyVector_21.push_back(202332320);
	// 		MyVector_21.push_back(30233230);

	// 		std::cout << "MyVector_21 contains:";
	// 		for (unsigned i = 0; i < MyVector_21.size(); i++)
	// 			std::cout << ' ' << MyVector_21[i];
	// 		std::cout << std::endl;
	// 		;
	// 		std::cout << "Clearing MyVector_21" << std::endl;
	// 		MyVector_21.clear();
	// 		MyVector_21.push_back(1101);
	// 		MyVector_21.push_back(2202);
	// 		std::cout << "MyVector_21 contains:";
	// 		for (unsigned i = 0; i < MyVector_21.size(); i++)
	// 			std::cout << ' ' << MyVector_21[i];
	// 		std::cout << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION get_allocator()
	// 		std::cout << "----------TESTING get_allocator()----------" << std::endl;
	// 		ft::vector<int> MyVector_22;
	// 		int* p;
	// 		unsigned int k;
	// 		p = MyVector_22.get_allocator().allocate(5);
	// 		for (k = 0; k < 5; k++) MyVector_22.get_allocator().construct(&p[k], k);
	// 		std::cout << "The allocated array contains:";
	// 		for (k = 0; k < 5; k++) std::cout << ' ' << p[k];
	// 		std::cout << std::endl;
	// 		for (k = 0; k < 5; k++) MyVector_22.get_allocator().destroy(&p[k]);
	// 		MyVector_22.get_allocator().deallocate(p, 5);
	// 		// !SECTION
	// 	}
	// 	// !SECTION VECTOR TESTS
	// }

	// {
	// 	// SECTION MAP TESTS
	// 	std::cout << std::endl;
	// 	std::cout << "---------------------------------------" << std::endl;
	// 	std::cout << "---------------MAP TESTS---------------" << std::endl;
	// 	std::cout << "---------------------------------------" << std::endl;
	// 	std::cout << std::endl;

	// 	{
	// 		// SECTION constructor()
	// 		std::cout << "----------TESTING constructors()----------" << std::endl;
    //         ft::map<char,int> first;
    //         first['a']=10;
    //         first['b']=30;
    //         first['c']=50;
    //         first['d']=70;
    //         ft::map<char,int> second (first.begin(),first.end());
    //         ft::map<char,int> third (second);
    //         ft::map<char,int,classcomp> fourth;
    //         int(*fn_pt)(int,int) = intcmp;
    //         ft::map<char,int,int(*)(int,int)> fifth (fn_pt);
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION operator= size()
	// 		std::cout << "----------TESTING operator= size()----------" << std::endl;
	// 		ft::map<char, int> first;
	// 		ft::map<char, int> second;
	// 		first['x'] = 8;
	// 		first['y'] = 16;
	// 		first['z'] = 32;
	// 		second = first;
	// 		first = ft::map<char, int>();
	// 		std::cout << "First and second shouldn't have the same size" << std::endl;
	// 		std::cout << "Size of first: " << first.size() << std::endl;
	// 		std::cout << "Size of second: " << second.size() << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION rbegin() rend()
	// 		std::cout << "----------TESTING rbegin() rend()----------" << std::endl;
	// 		ft::map<char, int> mymap;
	// 		mymap['x'] = 100;
	// 		mymap['y'] = 200;
	// 		mymap['z'] = 300;
	// 		ft::map<char, int>::reverse_iterator vache_qui_rit;
	// 		for (vache_qui_rit = mymap.rbegin(); vache_qui_rit != mymap.rend(); ++vache_qui_rit)
	// 			std::cout << vache_qui_rit->first << " => " << vache_qui_rit->second << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION empty()
	// 		std::cout << "----------TESTING empty()----------" << std::endl;
	// 		ft::map<char, int> mymap;
	// 		mymap['a'] = 10;
	// 		mymap['b'] = 20;
	// 		mymap['c'] = 30;
	// 		while (!mymap.empty()) {
	// 			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
	// 			mymap.erase(mymap.begin());
	// 		}
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

	// 	{
	// 		// SECTION max_size()
	// 		std::cout << "----------TESTING max_size()----------" << std::endl;
	// 		ft::map<int, int> mymap;
	// 		// long long max_size = mymap.max_size();
	// 		// if (mymap.max_size() != (std::numeric_limits<unsigned long>::max() / 20)) {
	// 		if (mymap.max_size() != (20)) { // TODO revert previous line
	// 			std::cout << "There is a problem" << std::endl;
	// 		} else {
	// 			std::cout << "max_size returns correct value" << std::endl;
	// 		}
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

    //     {
    //         // SECTION insert()
    //         std::cout << "----------TESTING insert()----------" << std::endl;
    //         ft::map<char,int> mymap;

    //         mymap.insert ( ft::pair<char,int>('a',100) );
    //         mymap.insert ( ft::pair<char,int>('z',200) );

    //         ft::pair<ft::map<char,int>::iterator,bool> ret;
    //         ret = mymap.insert ( ft::pair<char,int>('z',500) );
    //         if (ret.second==false) {
    //             std::cout << "element 'z' already existed";
    //             std::cout << " with a value of " << ret.first->second << std::endl;
    //         }

    //         ft::map<char,int>::iterator it = mymap.begin();
    //         mymap.insert (it, ft::pair<char,int>('b',300));
    //         mymap.insert (it, ft::pair<char,int>('c',400));

    //         ft::map<char,int> anothermap;
    //         anothermap.insert(mymap.begin(),mymap.find('c'));

    //         std::cout << "mymap contains:\n";
    //         for (it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;

    //         std::cout << "anothermap contains:\n";
    //         for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         // !SECTION
    //     }

	// 	{
	// 		// SECTION erase() find()
	// 		std::cout << "----------TESTING erase() find()----------" << std::endl;
	// 		ft::map<char, int> mymap;
	// 		ft::map<char, int>::iterator it;
	// 		mymap['a'] = 10;
	// 		mymap['b'] = 20;
	// 		mymap['c'] = 30;
	// 		mymap['d'] = 40;
	// 		mymap['e'] = 50;
	// 		mymap['f'] = 60;
    //         mymap.erase(mymap.begin());
    //         it = mymap.find('b');
	// 		mymap.erase(it);
	// 		mymap.erase('c');
	// 		it = mymap.find('e');
	// 		mymap.erase(it, mymap.end());
	// 		for (it = mymap.begin(); it != mymap.end(); ++it)
	// 			std::cout << it->first << " => " << it->second << std::endl;
	// 		// !SECTION
	// 		std::cout << std::endl;
	// 	}

    //     {
    //         // SECTION swap()
	// 		std::cout << "----------TESTING swap()----------" << std::endl;
    //         ft::map<char,int> foo,bar;
    //         foo['x']=100;
    //         foo['y']=200;
    //         bar['a']=11;
    //         bar['b']=22;
    //         bar['c']=33;
    //         foo.swap(bar);
    //         std::cout << "foo contains:\n";
    //         for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         std::cout << "bar contains:\n";
    //         for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         // SECTION clear()
    //         std::cout << "----------TESTING clear()----------" << std::endl;
    //         ft::map<char,int> mymap;
    //         mymap['x']=100;
    //         mymap['y']=200;
    //         mymap['z']=300;
    //         std::cout << "mymap contains:\n";
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         mymap.clear();
    //         mymap['a']=1101;
    //         mymap['b']=2202;
    //         std::cout << "mymap contains:\n";
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }


    //     {
    //         // SECTION key_comp()
    //         std::cout << "----------TESTING key_comp()----------" << std::endl;
    //         ft::map<char,int> mymap;
    //         ft::map<char,int>::key_compare mycomp = mymap.key_comp();
    //         mymap['a']=100;
    //         mymap['b']=200;
    //         mymap['c']=300;
    //         std::cout << "mymap contains:\n";
    //         char highest = mymap.rbegin()->first;     // key value of last element
    //         ft::map<char,int>::iterator it = mymap.begin();
    //         do {
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         } while ( mycomp((*it++).first, highest) );
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }


    //     {
    //         // SECTION value_comp()
    //         std::cout << "----------TESTING value_comp()----------" << std::endl;
    //         ft::map<char,int> mymap;
    //         mymap['x']=1001;
    //         mymap['y']=2002;
    //         mymap['z']=3003;
    //         std::cout << "mymap contains:\n";
    //         ft::map<char, int>::value_type highest = *mymap.rbegin();          // last element
    //         ft::map<char,int>::iterator it = mymap.begin();
    //         do {
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         } while ( mymap.value_comp()(*it++, highest) );
    //         // !SECTION
    //         std::cout << std::endl;
    //     }


    //     {
    //         // SECTION count()
    //         std::cout << "----------TESTING count()----------" << std::endl;
    //         ft::map<char,int> mymap;
    //         char c;
    //         mymap ['a']=101;
    //         mymap ['c']=202;
    //         mymap ['f']=303;
    //         for (c = 'a'; c < 'h'; c++)
    //         {
    //             std::cout << c;
    //             if (mymap.count(c)>0)
    //                 std::cout << " is an element of mymap." << std::endl;
    //             else 
    //                 std::cout << " is not an element of mymap." << std::endl;
    //         }
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION lower_bound() upper_bound()
    //         std::cout << "----------TESTING lower_bound() upper_bound()----------" << std::endl;
    //         ft::map<char,int> mymap;
    //         ft::map<char,int>::iterator itlow,itup;
    //         mymap['a']=20;
    //         mymap['b']=40;
    //         mymap['c']=60;
    //         mymap['d']=80;
    //         mymap['e']=100;
    //         itlow=mymap.lower_bound ('b');
    //         itup=mymap.upper_bound ('d');
    //         mymap.erase(itlow,itup);
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         // SECTION equal_range()
    //         std::cout << "----------TESTING equal_range()----------" << std::endl;
    //         ft::map<char,int> mymap;
    //         mymap['a']=10;
    //         mymap['b']=20;
    //         mymap['c']=30;
    //         ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
    //         ret = mymap.equal_range('b');
    //         std::cout << "lower bound points to: ";
    //         std::cout << ret.first->first << " => " << ret.first->second << std::endl;
    //         std::cout << "upper bound points to: ";
    //         std::cout << ret.second->first << " => " << ret.second->second << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         // SECTION get_allocator()
    //         std::cout << "----------TESTING get_allocator()----------" << std::endl;
    //         int psize;
    //         ft::map<char,int> mymap;
    //         ft::pair<const char,int>* p;
    //         p=mymap.get_allocator().allocate(5);
    //         psize = sizeof(ft::map<char,int>::value_type)*5;
    //         std::cout << "The allocated array has a size of " << psize << " bytes." << std::endl;
    //         mymap.get_allocator().deallocate(p,5);
    //         // !SECTION
    //         std::cout << std::endl;
    //     }
	// 	// !SECTION MAP TESTS
	// }

    // {
    //     // SECTION STACK TESTS
    //     std::cout << std::endl;
	// 	std::cout << "---------------------------------------" << std::endl;
	// 	std::cout << "--------------STACK TESTS--------------" << std::endl;
	// 	std::cout << "---------------------------------------" << std::endl;
	// 	std::cout << std::endl;
        
    //     {
    //         // SECTION empty()
    //         std::cout << "----------TESTING empty()----------" << std::endl;
    //         ft::stack<int> mystack;
    //         int sum (0);
    //         for (int i=1;i<=10;i++) mystack.push(i);
    //         while (!mystack.empty())
    //         {
    //             sum += mystack.top();
    //             mystack.pop();
    //         }
    //         std::cout << "total: " << sum << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         // SECTION size()
    //         std::cout << "----------TESTING size()----------" << std::endl;
    //         ft::stack<int> myints;
    //         std::cout << "0. size: " << myints.size() << std::endl;
    //         for (int i=0; i<5; i++) myints.push(i);
    //         std::cout << "1. size: " << myints.size() << std::endl;
    //         myints.pop();
    //         std::cout << "2. size: " << myints.size() << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         // SECTION top()
    //         std::cout << "----------TESTING top()----------" << std::endl;
    //         ft::stack<int> mystack;
    //         mystack.push(10);
    //         mystack.push(20);
    //         mystack.top() -= 5;
    //         std::cout << "mystack.top() is now " << mystack.top() << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         // SECTION push()
    //         std::cout << "----------TESTING push()----------" << std::endl;
    //         ft::stack<int> mystack;
    //         for (int i=0; i<5; ++i) mystack.push(i);
    //         std::cout << "Popping out elements...";
    //         while (!mystack.empty())
    //         {
    //             std::cout << ' ' << mystack.top();
    //             mystack.pop();
    //         }
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }
    //     //!SECTION STACK TESTS
    // }

    // {
    //     // SECTION SET TESTS (Bonus)
    //     std::cout << std::endl;
	// 	std::cout << "---------------------------------------" << std::endl;
	// 	std::cout << "---------------SET TESTS---------------" << std::endl;
	// 	std::cout << "---------------------------------------" << std::endl;
	// 	std::cout << std::endl;

    //     {
    //         //SECTION constructor()
    //         std::cout << "----------TESTING constructor()----------" << std::endl;
    //         ft::set<int> first;
    //         int myints[]= {10,20,30,40,50};
    //         ft::set<int> second (myints,myints + 5);
    //         ft::set<int> third (second);
    //         ft::set<int> fourth (second.begin(), second.end());
    //         ft::set<int,classcomp> fifth;
    //         int(*fn_pt)(int,int) = intcmp;
    //         ft::set<int,int(*)(int,int)> sixth (fn_pt);
    //         //!SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION operator=
    //         std::cout << "----------TESTING operator=----------" << std::endl;
    //         int myints[]={ 12,82,37,64,15 };
    //         ft::set<int> first (myints,myints+5);
    //         ft::set<int> second;
    //         second = first;
    //         first = ft::set<int>();
    //         std::cout << "Size of first: " << int (first.size()) << std::endl;
    //         std::cout << "Size of second: " << int (second.size()) << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION begin() end()
    //         std::cout << "----------TESTING begin() end()----------" << std::endl;
    //         int myints[] = {75,23,65,42,13};
    //         ft::set<int> myset (myints,myints+5);
    //         std::cout << "myset contains:";
    //         for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         //!SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION rbegin() rend()
    //         std::cout << "----------TESTING rbegin() rend()----------" << std::endl;
    //         int myints[] = {21,64,17,78,49};
    //         ft::set<int> myset (myints,myints+5);
    //         ft::set<int>::reverse_iterator rit;
    //         std::cout << "myset contains:";
    //         for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
    //             std::cout << ' ' << *rit;
    //         std::cout << std::endl;
    //         //!SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION empty()
    //         std::cout << "----------TESTING empty()----------" << std::endl;
    //         ft::set<int> myset;
    //         myset.insert(20);
    //         myset.insert(30);
    //         myset.insert(10);
    //         std::cout << "myset contains:";
    //         while (!myset.empty())
    //         {
    //             std::cout << ' ' << *myset.begin();
    //             myset.erase(myset.begin());
    //         }
    //         std::cout << std::endl;
    //         //!SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION size()
    //         std::cout << "----------TESTING size()----------" << std::endl;
    //         ft::set<int> myints;
    //         std::cout << "0. size: " << myints.size() << std::endl;
    //         for (int i=0; i<10; ++i) myints.insert(i);
    //         std::cout << "1. size: " << myints.size() << std::endl;
    //         myints.insert (100);
    //         std::cout << "2. size: " << myints.size() << std::endl;
    //         myints.erase(5);
    //         std::cout << "3. size: " << myints.size() << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION max_size()
    //         std::cout << "----------TESTING max_size()----------" << std::endl;
    //         int i;
    //         ft::set<int> myset;
    //         if (myset.max_size()>1000)
    //         {
    //             for (i=0; i<1000; i++) myset.insert(i);
    //             std::cout << "The set contains 1000 elements." << std::endl;
    //         }
    //         else std::cout << "The set could not hold 1000 elements." << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION insert()
    //         std::cout << "----------TESTING insert()----------" << std::endl;
    //         ft::set<int> myset;
    //         ft::set<int>::iterator it;
    //         ft::pair<ft::set<int>::iterator,bool> ret;
    //         for (int i=1; i<=5; ++i) myset.insert(i*10);
    //         ret = myset.insert(20);
    //         if (ret.second==false) it=ret.first;
    //         myset.insert (it,25);
    //         myset.insert (it,24);
    //         myset.insert (it,26);
    //         int myints[]= {5,10,15};
    //         myset.insert (myints,myints+3);
    //         std::cout << "myset contains:";
    //         for (it=myset.begin(); it!=myset.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         //!SECTION
    //         std::cout << std::endl;
    //     }

        {
            // SECTION erase()
            std::cout << "----------TESTING erase()----------" << std::endl;
            // FIXME leaks
            ft::set<int> myset;
            ft::set<int>::iterator it;
            for (int i=1; i<10; i++) myset.insert(i*10);
            it = myset.begin();
            ++it;
            myset.erase (it);
            myset.erase (40);
            it = myset.find (60);
            myset.erase (it, myset.end());
            std::cout << "myset contains:";
            for (it=myset.begin(); it!=myset.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << std::endl;
            // !SECTION
            std::cout << std::endl;
        }

    //     {
    //         //SECTION swap()
    //         std::cout << "----------TESTING swap()----------" << std::endl;
    //         int myints[]={12,75,10,32,20,25};
    //         ft::set<int> first (myints,myints+3);
    //         ft::set<int> second (myints+3,myints+6);
    //         first.swap(second);
    //         std::cout << "first contains:";
    //         for (ft::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         std::cout << "second contains:";
    //         for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION clear()
    //         std::cout << "----------TESTING clear()----------" << std::endl;
    //         ft::set<int> myset;
    //         myset.insert (100);
    //         myset.insert (200);
    //         myset.insert (300);
    //         std::cout << "myset contains:";
    //         for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         myset.clear();
    //         myset.insert (1101);
    //         myset.insert (2202);
    //         std::cout << "myset contains:";
    //         for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         //!SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION key_comp()
    //         std::cout << "----------TESTING key_comp()----------" << std::endl;
    //         ft::set<int> myset;
    //         int highest;
    //         ft::set<int>::key_compare mycomp = myset.key_comp();
    //         for (int i=0; i<=5; i++) myset.insert(i);
    //         std::cout << "myset contains:";
    //         highest=*myset.rbegin();
    //         ft::set<int>::iterator it=myset.begin();
    //         do {
    //             std::cout << ' ' << *it;
    //         } while ( mycomp(*(++it),highest) );
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION value_comp()
    //         std::cout << "----------TESTING value_comp()----------" << std::endl;
    //         ft::set<int> myset;
    //         ft::set<int>::value_compare mycomp = myset.value_comp();
    //         for (int i=0; i<=5; i++) myset.insert(i);
    //         std::cout << "myset contains:";
    //         int highest=*myset.rbegin();
    //         ft::set<int>::iterator it=myset.begin();
    //         do {
    //             std::cout << ' ' << *it;
    //         } while ( mycomp(*(++it),highest) );
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION find()
    //         std::cout << "----------TESTING find()----------" << std::endl;
    //         ft::set<int> myset;
    //         ft::set<int>::iterator it;
    //         for (int i=1; i<=5; i++) myset.insert(i*10);
    //         it=myset.find(20);
    //         myset.erase (it);
    //         myset.erase (myset.find(40));
    //         std::cout << "myset contains:";
    //         for (it=myset.begin(); it!=myset.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION count()
    //         std::cout << "----------TESTING count()----------" << std::endl;
    //         ft::set<int> myset;
    //         for (int i=1; i<5; ++i) myset.insert(i*3);
    //         for (int i=0; i<10; ++i)
    //         {
    //             std::cout << i;
    //             if (myset.count(i)!=0)
    //                 std::cout << " is an element of myset." << std::endl;
    //             else
    //                 std::cout << " is not an element of myset." << std::endl;
    //         }
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION lower_bound() upper_bound()
    //         std::cout << "----------TESTING lower_bound() upper_bound()----------" << std::endl;
    //         ft::set<int> myset;
    //         ft::set<int>::iterator itlow,itup;
    //         for (int i=1; i<10; i++) myset.insert(i*10);
    //         itlow=myset.lower_bound (30);
    //         itup=myset.upper_bound (60);
    //         myset.erase(itlow,itup);
    //         std::cout << "myset contains:";
    //         for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

    //     {
    //         //SECTION equal_range()
    //         std::cout << "----------TESTING equal_range()----------" << std::endl;
    //         ft::set<int> myset;
    //         for (int i=1; i<=5; i++) myset.insert(i*10);
    //         // ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ret;
    //         ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret; // FIXME revert previous line
    //         ret = myset.equal_range(30);
    //         std::cout << "the lower bound points to: " << *ret.first << std::endl;
    //         std::cout << "the upper bound points to: " << *ret.second << std::endl;
    //         // !SECTION
    //         std::cout << std::endl;
    //     }

<<<<<<< HEAD
    //     {
    //         //SECTION get_allocator()
    //         std::cout << "----------TESTING get_allocator()----------" << std::endl;
    //         ft::set<int> myset;
    //         int * p;
    //         unsigned int i;
    //         p=myset.get_allocator().allocate(5);
    //         for (i=0; i<5; i++) p[i]=(i+1)*10;
    //         std::cout << "The allocated array contains:";
    //         for (i=0; i<5; i++) std::cout << ' ' << p[i];
    //         std::cout << std::endl;
    //         myset.get_allocator().deallocate(p,5);
    //         // !SECTION
    //         std::cout << std::endl;
    //     }
    //     // !SECTION SET TESTS
    // }
=======
        {
            //SECTION get_allocator()
            std::cout << "----------TESTING get_allocator()----------" << std::endl;
            ft::set<int> myset;
            int * p;
            unsigned int i;
            p=myset.get_allocator().allocate(5);
            for (i=0; i<5; i++) p[i]=(i+1)*10;
            std::cout << "The allocated array contains:";
            for (i=0; i<5; i++) std::cout << ' ' << p[i];
            std::cout << std::endl;
            myset.get_allocator().deallocate(p,5);
            // !SECTION
            std::cout << std::endl;
        }
        // !SECTION SET TESTS (Bonus)
    }
>>>>>>> 06a3e2229448cf289dfffb70bc7abd334d599526
	return (0);
}