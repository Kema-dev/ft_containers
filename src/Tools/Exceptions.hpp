#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>

class allocFail : public std::exception {
   public:
	virtual const char* what() const throw() {
		return ("Memory allocation failed");
	}
};

class duplicateKey : public std::exception {
   public:
	virtual const char* what() const throw() {
		return ("Provided key is a duplicate");
	}
};

class OutOfRangeException : public std::exception {
   public:
	const char* what() const throw() {
		return "Request is out of bounds";
	}
};

#endif
