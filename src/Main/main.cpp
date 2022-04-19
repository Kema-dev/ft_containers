#include <stdio.h>

#include <deque>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"
#include "../Tools/RBT.hpp"

// using namespace std;
// using namespace ft;

#include <map>

int main(void) {
	ft::map<int, int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(2, 2));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(4, 4));
	m.insert(pair<int, int>(5, 5));
	m.insert(pair<int, int>(6, 6));
	m.insert(pair<int, int>(7, 7));
	m.insert(pair<int, int>(8, 8));
	m.insert(pair<int, int>(9, 9));
	m.insert(pair<int, int>(10, 10));
	m.insert(pair<int, int>(11, 11));
	m.insert(pair<int, int>(12, 12));
	m.insert(pair<int, int>(13, 13));
	m.insert(pair<int, int>(14, 14));
	m.insert(pair<int, int>(15, 15));
	// print the map
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	// print the map reversely
	for (map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}