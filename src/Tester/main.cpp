#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"
#include "../Stack/Stack.hpp"
#include "../Set/Set.hpp"

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

    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n'; 

    //!SECTION



    return (0);
}