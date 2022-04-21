#ifndef NODE_HPP
#define NODE_HPP

#include "../Tools/Pair.hpp"

enum e_color {
	black,
	red
};
enum e_branch {
	left,
	right
};

#define RED "\e[31m"
#define BLACK "\e[30m"
#define DEFAULT "\e[39m"

using namespace std;

// SECTION namespace ft
namespace ft {

// SECTION Node
template <typename K, typename V>
class node {
   public:
	ft::pair<const K, V> pair;
	e_color color;
	node* parent;
	node* left;
	node* right;

	node(ft::pair<const K, V>& dpair)
		: pair(dpair), color(red), parent(NULL), left(NULL), right(NULL){};
	~node(){};
	bool operator<(const node& other) const {
		return (pair < other.pair);
	};
	bool operator<=(const node& other) const {
		return (pair <= other.pair);
	};
	bool operator>(const node& other) const {
		return (pair > other.pair);
	};
	bool operator>=(const node& other) const {
		return (pair >= other.pair);
	};
	bool operator==(const node& other) const {
		return (pair == other.pair);
	};
	bool operator!=(const node& other) const {
		return (pair != other.pair);
	};
};
}  // namespace ft
// !SECTION Node

#endif
