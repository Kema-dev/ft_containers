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
	ft::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	for (ft::set<int>::iterator it = s.begin(); it != s.end(); ++it)
		std::cout << *it << " ";
	return 0;
}

// #include <map>

// int main(void) {
// 	std::map<int, std::string> map;
// 	for (int i = 1; i <= 25; ++i)
// 		map.insert(std::pair<int, std::string>(i, std::to_string(i)));
// 	map[600];
// 	for (std::map<int, std::string>::iterator it = map.begin(); it != map.end(); ++it) {
// 		std::cout << it->first << " " << it->second << std::endl;
// 	}
// }

