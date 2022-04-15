#include <deque>
#include <iostream>
#include <string>

#include "../Tools/RBT.hpp"
#include <stdio.h>

using namespace std;
using namespace ft;

int main(void) {
	RBT<int, string> tree;
	try {
		tree = RBT<int, string>();
	} catch (exception& e) {
		cerr << e.what() << endl;
	}
	int max = 100;
	try {
		int nb;
		string str;
		for (nb = 0; nb < max; nb++) {
			char buf[10];
			sprintf(buf, "%d", nb);
			str = string(buf);
			tree.add(make_kvp(nb, str));
		}
		tree.print();
	} catch (exception& e) {
		cerr << e.what() << endl;
	}
}