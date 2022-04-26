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
	node* operator=(const node& other) {
		pair = other.pair;
		color = other.color;
		parent = other.parent;
		left = other.left;
		right = other.right;
		return this;
	};
	/*
	INFO Get the nodePtr of the successor of <node> (first node with key > <node>'s key)
	INFO No exception
	*/
	node* getSuccessor(void) {
		node* nodePtr = std::allocator<node>().allocate(1);
		nodePtr = this;
		if (nodePtr->right != NULL) {
			nodePtr = nodePtr->right;
			while (nodePtr->left != NULL)
				nodePtr = nodePtr->left;
		} else {
			while (nodePtr->parent != NULL && nodePtr->parent->right == nodePtr)
				nodePtr = nodePtr->parent;
			nodePtr = nodePtr->parent;
		}
		return nodePtr;
	};
	/*
	INFO Get the node* of the predecessor of <node> (first node with key < <node>'s key)
	INFO No exception
	*/
	node* getPredecessor(void) {
		node* nodePtr = std::allocator<node>().allocate(1);
		nodePtr = this;
		if (nodePtr->left != NULL) {
			nodePtr = nodePtr->left;
			while (nodePtr->right != NULL)
				nodePtr = nodePtr->right;
		} else {
			while (nodePtr->parent != NULL && nodePtr->parent->left == nodePtr)
				nodePtr = nodePtr->parent;
			nodePtr = nodePtr->parent;
		}
		return nodePtr;
	};
};
}  // namespace ft
// !SECTION Node

#endif
