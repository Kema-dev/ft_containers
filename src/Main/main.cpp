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

int main(void) {
	ft::map<int, std::string> map;
	for (int i = 1; i <= 25; ++i)
		map.insert(i, std::to_string(i));
	for (int i = 1; i <= 25; ++i)
		std::cout << map[i] << std::endl;
	map.print();
	return 0;
}
