#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"

void print_v(ft::vector<int>& v) {
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// void print_m(ft::map<int, std::string>& m) {
// 	for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

#include <vector>

int main(void) {
	ft::map<int, std::string> m;
	m[1];
	// print_m(m);
	return 0;
}
