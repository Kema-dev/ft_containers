#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"
#include "../Stack/Stack.hpp"
#include "../Set/Set.hpp"
#include "../Tools/Utils.hpp"

#include <vector>

int main(void)
{
    //SECTION VECTOR TESTS
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

    std::cout << std::endl;
    // std::cout << "char: " << std::is_integral<size_t>::value << std::endl;
    ft::vector<int> foo (3,100);
    // ft::vector<int> bar (5,200);
    ft::vector<int> bar;
    bar.push_back(1);
    bar.push_back(1);
    bar.push_back(1);
    bar.push_back(1);
    bar.push_back(1);
    // std::cout << ft::is_integral<int>::value << std::endl;
    ft::vector<int> baz (bar.begin(), bar.end());

    // foo.swap(bar);

    std::cout << "baz contains:";
    for (unsigned i=0; i<baz.size(); i++)
        std::cout << ' ' << baz[i];
    std::cout << '\n';

    // std::cout << "bar contains:";
    // for (unsigned i=0; i<bar.size(); i++)
    //     std::cout << ' ' << bar[i];
    // std::cout << '\n'; 

    //!SECTION



    return (0);
}