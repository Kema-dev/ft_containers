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
	typedef ft::iterator_traits<ft::vector<int> > traits;
	if (typeid(traits::iterator_category)==typeid(std::bidirectional_iterator_tag))
    	std::cout << "ft::vector<int> is a bidirectional iterator" << std::endl;
	ft::map<int, std::string> m;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	traits::difference_type d = m.size();
	std::cout << "m.size() = " << d << std::endl;
	m.insert(ft::pair<int, std::string>(1, "a"));
	m.print();
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
