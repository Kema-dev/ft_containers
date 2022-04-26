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
	for (int i = 1; i <= 25; ++i) {
		map.insert(ft::pair<const int, std::string>(i, std::to_string(i)));
	}
	for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;
	for (int i = 1; i <= 25; ++i) {
		std::cout << map[i] << std::endl;
	}
	cout << "map size: " << map.size() << endl;
	map.print();
	return 0;
}

// #include <map>

// int main(void) {
// 	std::map<int, std::string> map;
// 	for (int i = 1; i <= 25; ++i)
// 		map.insert(std::pair<const int, std::string>(i, std::to_string(i)));
// 	for (std::map<int, std::string>::iterator it = map.begin(); it != map.end(); ++it) {
// 		std::cout << it->first << " " << it->second << std::endl;
// 	}
// }

