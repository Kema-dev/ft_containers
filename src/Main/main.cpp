#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"
#include "../Iterators/Iterator.hpp"
#include "../Iterators/ReverseIterator.hpp"

void print_v(ft::vector<int>& v) {
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void print_m(ft::map<int, std::string>& m) {
	for (ft::map<int, std::string>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#include <vector>

int main(void) {
	ft::map<int, std::string> m;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	m[5] = "five";
	print_m(m);
	return 0;
}
