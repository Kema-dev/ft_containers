#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"
#include "../Stack/Stack.hpp"
#include "../Set/Set.hpp"

void print_v(ft::vector<int>& v) {
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(void) {
	ft::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	print_v(v);
	return 0;
}

// #include <set>

// int main(void) {
// 	std::set<int> s;
// 	s.insert(1);
// 	s.insert(2);
// 	s.insert(3);
// 	s.insert(4);
// 	for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
// 		std::cout << *it << " ";
// 	return 0;
// }
