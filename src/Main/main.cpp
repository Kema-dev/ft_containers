#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"
#include "../Stack/Stack.hpp"

void print_v(ft::vector<int>& v) {
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(void) {
	ft::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	s.pop();
	for (ft::stack<int>::iterator it = s.begin(); it != s.end(); ++it)
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

