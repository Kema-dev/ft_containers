#include <iostream>

using namespace std;

class allocFail : public exception
{
	public:
		virtual const char*	what() const throw() {
			return ("Memory allocation failed");
		}
};

class duplicateKey : public exception
{
	public:
		virtual const char*	what() const throw() {
			return ("Provided key is a duplicate");
		}
};
