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
    {
        // SECTION VECTOR TESTS
        {
            // SECTION pop_back()
            std::cout << "----------TESTING pop_back()----------" << std::endl;
            ft::vector<int> MyVector_1;
            MyVector_1.push_back(1);
            MyVector_1.push_back(2);
            MyVector_1.push_back(3);
            MyVector_1.push_back(4);
            MyVector_1.push_back(5);
            std::cout << "MyVector_1: ";
            for (ft::vector<int>::iterator it = MyVector_1.begin(); it != MyVector_1.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            MyVector_1.pop_back();
            std::cout << "MyVector_1 should contain: 1 2 3 4" << std::endl;
            std::cout << "MyVector_1 after pop_back(): ";
            for (ft::vector<int>::iterator it = MyVector_1.begin(); it != MyVector_1.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION swap()
            std::cout << "----------TESTING swap() operator[]----------" << std::endl;
            ft::vector<int> MyVector_2(3, 100);
            ft::vector<int> MyVector_3(5, 200);
            std::cout << "MyVector_2 contains: ";
            for (ft::vector<int>::iterator it = MyVector_2.begin(); it != MyVector_2.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << "MyVector_3 contains: ";
            for (ft::vector<int>::iterator it = MyVector_3.begin(); it != MyVector_3.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            std::cout << "Swapping MyVector_2 and MyVector_3" << std::endl;
            MyVector_2.swap(MyVector_3);
            std::cout << "MyVector_2 contains:"; 
            for (unsigned i = 0; i < MyVector_2.size(); i++)
                std::cout << ' ' << MyVector_2[i];
            std::cout << std::endl;
            std::cout << "MyVector_3 contains:";
            for (unsigned i = 0; i < MyVector_3.size(); i++)
                std::cout << ' ' << MyVector_3[i];
            std::cout << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION constructors
            std::cout << "----------TESTING constructors----------" << std::endl;
            ft::vector<int> MyVector_4;
            ft::vector<int> MyVector_5(4, 100);
            std::cout << "MyVector_5 should contain: 100 100 100 100" << std::endl;
            std::cout << "MyVector_5 contains:";
            for (unsigned i = 0; i < MyVector_5.size(); i++)
                std::cout << ' ' << MyVector_5[i];
            std::cout << std::endl;
            ft::vector<int> MyVector_6(MyVector_5.begin(), MyVector_5.end());
            std::cout << "MyVector_6 should contain: 100 100 100 100" << std::endl;
            std::cout << "MyVector_6 contains:";
            for (unsigned i = 0; i < MyVector_6.size(); i++)
                std::cout << ' ' << MyVector_6[i];
            std::cout << std::endl;
            std::cout << "MyVector_7 should contain: 100 100 100 100" << std::endl;
            ft::vector<int> MyVector_7(MyVector_6);
            std::cout << "MyVector_7 contains:";
            for (unsigned i = 0; i < MyVector_7.size(); i++)
                std::cout << ' ' << MyVector_7[i];
            std::cout << std::endl;
            int myints[] = {16, 2, 77, 29};
            ft::vector<int> MyVector_8(myints, myints + sizeof(myints) / sizeof(int));
            std::cout << "MyVector_8 should contain: 16 2 77 29" << std::endl;
            std::cout << "MyVector_8 contains:";
            for (ft::vector<int>::iterator it = MyVector_8.begin(); it != MyVector_8.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << std::endl;
            // SECTION
            std::cout << std::endl;
        }

        {
            // SECTION reverse iterators
            std::cout << "----------TESTING reverse iterators----------" << std::endl;
            ft::vector<int> MyVector_9(5);
            int i = 0;
            ft::vector<int>::reverse_iterator rit = MyVector_9.rbegin();
            for (; rit != MyVector_9.rend(); ++rit)
                *rit = ++i;
            std::cout << "MyVector_9 should contain: 5 4 3 2 1" << std::endl;
            std::cout << "MyVector_9 contains:";
            for (ft::vector<int>::iterator it = MyVector_9.begin(); it != MyVector_9.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION size() capacity() max_size()
            std::cout << "----------TESTING size() capacity() max_size()----------" << std::endl;
            ft::vector<int> MyVector_10;
            for (int i = 0; i < 100; i++) MyVector_10.push_back(i);
            std::cout << "MyVector_10 size: " << MyVector_10.size() << "\n";
            std::cout << "MyVector_10 capacity: " << MyVector_10.capacity() << "\n";
            std::cout << "MyVector_10 max_size: " << MyVector_10.max_size() << "\n";
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION empty()
            std::cout << "----------TESTING empty()----------" << std::endl;
            ft::vector<int> MyVector_11;
            int sum(0);
            for (int i = 1; i <= 10; i++) MyVector_11.push_back(i);
            while (!MyVector_11.empty()) {
                sum += MyVector_11.back();
                MyVector_11.pop_back();
            }
            std::cout << "MyVector_11 total: " << sum << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION reserve()
            std::cout << "----------TESTING reserve()----------" << std::endl;
            ft::vector<int>::size_type sz;
            ft::vector<int> MyVector_12;
            sz = MyVector_12.capacity();
            std::cout << "Making MyVector_12 grow:" << std::endl;
            for (int i = 0; i < 100; ++i) {
                MyVector_12.push_back(i);
                if (sz != MyVector_12.capacity()) {
                    sz = MyVector_12.capacity();
                    std::cout << "MyVector_12 capacity changed: " << sz << std::endl;
                }
            }
            ft::vector<int> MyVector_13;
            sz = MyVector_13.capacity();
            MyVector_13.reserve(100);
            std::cout << "Making MyVector_13 grow:" << std::endl;
            for (int i = 0; i < 100; ++i) {
                MyVector_13.push_back(i);
                if (sz != MyVector_13.capacity()) {
                    sz = MyVector_13.capacity();
                    std::cout << "MyVector_13 capacity changed: " << sz << std::endl;
                }
            }
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION at()
            std::cout << "----------TESTING at()----------" << std::endl;
            ft::vector<int> MyVector_14(10);
            for (unsigned i = 0; i < MyVector_14.size(); i++)
                MyVector_14.at(i) = i;
            std::cout << "MyVector_14 contains:";
            for (unsigned i = 0; i < MyVector_14.size(); i++)
                std::cout << ' ' << MyVector_14.at(i);
            std::cout << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION front() back()
            std::cout << "----------TESTING front() back()----------" << std::endl;
            ft::vector<int> MyVector_15;
            MyVector_15.push_back(78);
            MyVector_15.push_back(16);
            std::cout << "Front of MyVector_15: " << MyVector_15.front() << std::endl;
            std::cout << "Back of MyVector_15: " << MyVector_15.back() << std::endl;
            std::cout << "Front of MyVector_15 should be 62 (78-16)" << std::endl;
            MyVector_15.front() -= MyVector_15.back();
            std::cout << "Front of MyVector_15 is now " << MyVector_15.front() << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION assign()
            std::cout << "----------TESTING assign()----------" << std::endl;
            ft::vector<int> MyVector_16;
            ft::vector<int> MyVector_17;
            ft::vector<int> MyVector_18;
            MyVector_16.assign(7, 100);
            ft::vector<int>::iterator ite;
            ite = MyVector_16.begin() + 1;
            MyVector_17.assign(ite, MyVector_16.end() - 1);
            int ints[] = {1776, 7, 4};
            MyVector_18.assign(ints, ints + 3);
            std::cout << "Size of MyVector_16: " << int(MyVector_16.size()) << std::endl;
            std::cout << "Size of MyVector_17: " << int(MyVector_17.size()) << std::endl;
            std::cout << "Size of MyVector_18: " << int(MyVector_18.size()) << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION insert() erase()
            std::cout << "----------TESTING insert() erase()----------" << std::endl;
            ft::vector<int> MyVector_19(3, 100);
            ft::vector<int>::iterator iter;


            iter = MyVector_19.begin();
            std::cout << "MyVector_19 contains:";
            for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
                std::cout << ' ' << *iter;
            std::cout << std::endl;

            iter = MyVector_19.begin();
            iter = MyVector_19.insert(iter, 200);
            std::cout << "MyVector_19 contains:";
            for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
                std::cout << ' ' << *iter;
            std::cout << std::endl;

            iter = MyVector_19.begin();
            MyVector_19.insert(iter, 2, 300);
            std::cout << "MyVector_19 contains:";
            for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
                std::cout << ' ' << *iter;
            std::cout << std::endl;

            iter = MyVector_19.begin();
            ft::vector<int> MyVector_20(2, 400);
            MyVector_19.insert(iter, MyVector_20.begin(), MyVector_20.end());
            std::cout << "MyVector_19 contains:";
            for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
                std::cout << ' ' << *iter;
            std::cout << std::endl;

            int myarray[] = {501, 502, 503};
            MyVector_19.insert(MyVector_19.begin(), myarray, myarray + 3);
            std::cout << "MyVector_19 contains:";
            for (iter = MyVector_19.begin(); iter < MyVector_19.end(); iter++)
                std::cout << ' ' << *iter;
            std::cout << std::endl;
            //! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION clear()
            std::cout << "----------TESTING clear()----------" << std::endl;
            ft::vector<int> MyVector_21;
            MyVector_21.push_back (12332300);
            MyVector_21.push_back (202332320);
            MyVector_21.push_back (30233230);

            std::cout << "MyVector_21 contains:";
            for (unsigned i=0; i<MyVector_21.size(); i++)
                std::cout << ' ' << MyVector_21[i];
            std::cout << std::endl;;
            std::cout << "Clearing MyVector_21" << std::endl;
            MyVector_21.clear();
            MyVector_21.push_back (1101);
            MyVector_21.push_back (2202);
            std::cout << "MyVector_21 contains:";
            for (unsigned i=0; i<MyVector_21.size(); i++)
                std::cout << ' ' << MyVector_21[i];
            std::cout << std::endl;
            // ! SECTION
            std::cout << std::endl;
        }

        {
            // SECTION get_allocator()
            std::cout << "----------TESTING get_allocator()----------" << std::endl;
            ft::vector<int> MyVector_22;
            int* p;
            unsigned int k;
            p = MyVector_22.get_allocator().allocate(5);
            for (k = 0; k < 5; k++) MyVector_22.get_allocator().construct(&p[k], k);
            std::cout << "The allocated array contains:";
            for (k = 0; k < 5; k++) std::cout << ' ' << p[k];
            std::cout << std::endl;
            for (k = 0; k < 5; k++) MyVector_22.get_allocator().destroy(&p[k]);
            MyVector_22.get_allocator().deallocate(p, 5);
            //! SECTION
        }
        // SECTION VECTOR TESTS
    }

    {
        //SECTION MAP TESTS
        {
            // SECTION constructor()

            ft::map<char,int> first;

            first['a']=10;
            first['b']=30;
            first['c']=50;
            first['d']=70;

            ft::map<char,int> second (first.begin(),first.end());

            ft::map<char,int> third (second);

        }


        //!SECTION
    }
	return (0);
}