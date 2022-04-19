#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>

// #include "../Map/Map.hpp"
#include "../Vector/Vector.hpp"
#include "../Iterators/Iterator.hpp"
#include "../Iterators/ReverseIterator.hpp"

int main(void) {
	ft::vector<int> v;
	// push back numbers from 1 to 10
	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
	}
	// print all numbers
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
