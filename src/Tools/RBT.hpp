#ifndef FT_CONTAINERS_RBT_HPP
#define FT_CONTAINERS_RBT_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "Exceptions.hpp"
#include "KVP.hpp"

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
	kvp<K, V> pair;
	e_color color;
	node* parent;
	node* left;
	node* right;

	node(kvp<K, V>& dpair)
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
// !SECTION Node

// SECTION RBT
template <typename K, typename V>
class RBT {
   public:
	typedef node<K, V>* nodePtr;
	typedef node<K, V>& nodeRef;
	typedef node<K, V> nodeType;

   private:
	nodePtr _root;
	size_t	_size;

   public:
	// SECTION Constructors / Destructors
	// INFO Create an empty tree
	RBT(void)
		: _root(NULL), _size(0) {};
	/*
	INFO Create a tree with root node containing KVP <dpair>
	INFO Can throw exception (self: allocFail)
	*/
	RBT(kvp<K, V> dpair) {
		_root = new node<K, V>(dpair);
		if (!_root) {
			throw allocFail();
		}
		_root->color = black;
		_size = 1;
	};
	/*
	INFO Create a RBT with RBT <src> as "root"
	INFO Can throw exception (calls)
	*/
	RBT(RBT const& src) {
		*this = src;
		_root->color = black;
	};
	/*
	INFO Clear the tree from nodePtr <node>
	INFO No exception
	*/
	void clear(nodePtr node) {
		if (!node)
			return;
		clear(node->left);
		clear(node->right);
		_size--;
		delete node;
	};
	/*
	INFO Clear the entire tree
	INFO No exception
	*/
	~RBT(void) {
		clear(_root);
	};
	// !SECTION Constructors / Destructors
	// SECTION Operators and basic functions
	// INFO Get the root node
	nodePtr getRoot(void) const {
		return _root;
	};
	/*
	INFO Get a mint new node with KVP <dpair>
	INFO Can throw exception (self: allocFail)
	*/
	nodePtr standaloneNode(kvp<K, V> dpair) const {
		nodePtr buf = new node<K, V>(dpair);
		if (!buf) {
			throw allocFail();
		}
		return buf;
	};
	/*
	INFO Make RBT <this> become a copy of RBT <rhs>
	INFO Can throw exception (calls)
	*/
	RBT& operator=(RBT const& rhs) {
		clear(_root);
		_root = copy(rhs._root);
		return *this;
	};
	/*
	INFO Get a copy of nodePtr <node>
	INFO Can throw exception (calls)
	*/
	nodePtr copy(nodePtr node) {
		if (!node)
			return NULL;
		nodePtr newNode;
		newNode = standaloneNode(node->pair);
		newNode->color = node->color;
		newNode->parent = NULL;
		_size++;
		newNode->left = copy(node->left);
		newNode->right = copy(node->right);
		if (newNode->left)
			newNode->left->parent = newNode;
		if (newNode->right)
			newNode->right->parent = newNode;
		return newNode;
	};
	/*
	INFO Swap RBT <this> and RBT <src>
	INFO No exception
	*/
	// REVIEW Maybe not needed
	void swap(RBT& src) {
		nodePtr bufRoot = _root;
		_root = src._root;
		_size = src._size;
		src._root = bufRoot;
	}
	// !SECTION Operators and basic functions
	// SECTION Insertion
	/*
	INFO /!\ DO NOT USE /!\ (Use "add" instead)
	INFO Can throw exception (calls)
	*/
	nodePtr insert(kvp<K, V> dpair) {
		nodePtr newNode = standaloneNode(dpair);
		nodePtr curNode = _root;
		nodePtr parent = NULL;
		while (curNode) {
			parent = curNode;
			if (newNode->pair.key < curNode->pair.key)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}
		newNode->parent = parent;
		if (!parent) {
			_root = newNode;
			_root->color = black;
			return newNode;
		} else if (newNode->pair.key < parent->pair.key)
			parent->left = newNode;
		else if (newNode->pair.key > parent->pair.key)
			parent->right = newNode;
		else {
			delete newNode;
			throw duplicateKey();
		}
		newNode->color = red;
		_size++;
		return newNode;
	};
	/*
	INFO Add KVP <dpair> to the tree
	INFO Can throw exception (calls)
	*/
	void add(kvp<K, V> dpair) {
		nodePtr newNode = insert(dpair);
		fixInsert(newNode);
	};
	/*
	INFO Fix the RBT after insertion of nodePtr <node>
	INFO Can throw exception (calls)
	*/
	void fixInsert(nodePtr node) {
		while (node->parent && node->parent->color == red) {
			if (node->parent == node->parent->parent->left) {
				nodePtr uncle = node->parent->parent->right;
				if (uncle && uncle->color == red) {
					node->parent->color = black;
					uncle->color = black;
					node->parent->parent->color = red;
					node = node->parent->parent;
				} else {
					if (node == node->parent->right) {
						node = node->parent;
						leftRotate(node);
					}
					node->parent->color = black;
					node->parent->parent->color = red;
					rightRotate(node->parent->parent);
				}
			} else {
				nodePtr uncle = node->parent->parent->left;
				if (uncle && uncle->color == red) {
					node->parent->color = black;
					uncle->color = black;
					node->parent->parent->color = red;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left) {
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = black;
					node->parent->parent->color = red;
					leftRotate(node->parent->parent);
				}
			}
		}
		_root->color = black;
	};
	/*
	INFO Rotate nodePtr <node> to the left
	INFO Can throw exception (calls)
	*/
	void leftRotate(nodePtr node) {
		nodePtr right = node->right;
		node->right = right->left;
		if (right->left)
			right->left->parent = node;
		right->parent = node->parent;
		if (!node->parent)
			_root = right;
		else if (node == node->parent->left)
			node->parent->left = right;
		else
			node->parent->right = right;
		right->left = node;
		node->parent = right;
	};
	/*
	INFO Rotate nodePtr <node> to the right
	INFO Can throw exception (calls)
	*/
	void rightRotate(nodePtr node) {
		nodePtr left = node->left;
		node->left = left->right;
		if (left->right)
			left->right->parent = node;
		left->parent = node->parent;
		if (!node->parent)
			_root = left;
		else if (node == node->parent->right)
			node->parent->right = left;
		else
			node->parent->left = left;
		left->right = node;
		node->parent = left;
	};
	// !SECTION Insertion
	// SECTION Deletion
	/*
	INFO Remove nodePtr <node> from the tree
	INFO Can throw exception (calls)
	*/
	void remove(nodePtr node) {
		if (!node)
			return;
		nodePtr curNode = node;
		nodePtr parent = node->parent;
		nodePtr child = NULL;
		nodePtr sibling = NULL;
		bool isLeft = false;
		if (node->left && node->right) {
			curNode = node->right;
			while (curNode->left)
				curNode = curNode->left;
			child = curNode->right;
			sibling = curNode->parent;
			isLeft = (curNode == sibling->left);
			curNode->parent = parent;
			curNode->left = node->left;
			curNode->left->parent = curNode;
			curNode->right = node->right;
			curNode->right->parent = curNode;
			curNode->color = node->color;
		} else if (node->left)
			child = node->left;
		else
			child = node->right;
		if (!parent)
			_root = child;
		else if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
		if (child)
			child->parent = parent;
		if (node->color == black)
			fixRemove(child, sibling, isLeft);
		delete node;
		_size--;
	};
	/*
	INFO Fix the RBT after deletion of nodePtr <node>
	INFO Can throw exception (calls)
	*/
	void fixRemove(nodePtr node, nodePtr sibling, bool isLeft) {
		if (!node)
			return;
		if (node->color == red) {
			node->color = black;
			return;
		}
		if (sibling) {
			if (sibling->color == red) {
				sibling->color = black;
				if (isLeft) {
					node->parent->color = red;
					rightRotate(node->parent);
				} else {
					node->parent->color = red;
					leftRotate(node->parent);
				}
				sibling = node->parent->left;
			}
			if (sibling->left->color == black && sibling->right->color == black) {
				sibling->color = red;
				node = node->parent;
			} else {
				if (sibling->left->color == black) {
					sibling->right->color = black;
					sibling->color = red;
					leftRotate(sibling);
					sibling = node->parent->left;
				}
				sibling->color = node->parent->color;
				node->parent->color = black;
				sibling->left->color = black;
				rightRotate(node->parent);
				node = _root;
			}
		} else {
			node->color = black;
			node = node->parent;
		}
		fixRemove(node, node->left, true);
		fixRemove(node, node->right, false);
	};
	// !SECTION Deletion
	// SECTION Searching
	/*
	INFO Search for a node by <key>, from <this>'s root
	INFO No exception
	*/
	nodePtr searchKey(K key) {
		return (searchKey(_root, key));
	};
	/*
	INFO Search for a node by <key>, from specified nodePtr <start>
	INFO No exception
	*/
	nodePtr searchKey(nodePtr start, K key) {
		if (!start || !key) {
			return NULL;
		} else {
			if (key == start->pair.key) {
				return start;
			} else if (key < start->pair.key) {
				return searchKey(start->left, key);
			} else {
				return searchKey(start->right, key);
			}
		}
	};
	// !SECTION Searching
	// SECTION Printing
	/*
	INFO Set the terminal color according to node color
	INFO No exception
	*/
	void setColor(nodePtr node) {
		if (node->color == red)
			cout << RED;
		else if (node->color == black)
			cout << BLACK;
	};
	/*
	INFO Set the terminal color to default (white)
	INFO No exception
	*/
	void unsetColor(void) {
		cout << DEFAULT;
	};
	// INFO /!\ DO NOT USE /!\ (Use function "print" instead)
	void recursivePrint(const string& prefix, const nodePtr node, bool isLeft) {
		if (node != NULL) {
			cout << prefix;
			cout << (isLeft ? "├──" : "└──");
			setColor(node);
			cout << node->pair.key << ":" << node->pair.value << endl;
			unsetColor();
			recursivePrint(prefix + (isLeft ? "│   " : "    "), node->left, true);
			recursivePrint(prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}
	/*
	INFO Prints the tree from specified nodePtr <node>
	INFO No exception
	*/
	void print(const nodePtr node) {
		recursivePrint("", node, false);
	};
	/*
	INFO Prints <this> tree from root
	INFO No exception
	*/
	void print(void) {
		recursivePrint("", _root, false);
	};
	// !SECTION Printing
	/*
	INFO Return the root nodePtr
	INFO No exception
	*/
	nodePtr getRoot(void) {
		return _root;
	};
	/*
	INFO Return the size of <this> tree
	INFO No exception
	*/
	size_t getSize(void) {
		return _size;
	};
	/*
	INFO Get the nodePtr of the minimum value
	INFO No exception
	*/
	nodePtr getMin(void) {
		nodePtr curNode = _root;
		while (curNode->left)
			curNode = curNode->left;
		return curNode;
	};
	/*
	INFO Get the nodePtr of the maximum value
	INFO No exception
	*/
	nodePtr getMax(void) {
		nodePtr curNode = _root;
		while (curNode->right)
			curNode = curNode->right;
		return curNode;
	};
	/*
	INFO Get the nodePtr of the successor of <node> (first node with key > <node>'s key)
	INFO No exception
	*/
	nodePtr getSuccessor(nodePtr node) {
		if (node->right) {
			node = node->right;
			while (node->left)
				node = node->left;
			return node;
		} else {
			nodePtr parent = node->parent;
			while (parent && node == parent->right) {
				node = parent;
				parent = parent->parent;
			}
			return parent;
		}
	};
	/*
	INFO Get the nodePtr of the predecessor of <node> (first node with key < <node>'s key)
	INFO No exception
	*/
	nodePtr getPredecessor(nodePtr node) {
		if (node->left) {
			node = node->left;
			while (node->right)
				node = node->right;
			return node;
		} else {
			nodePtr parent = node->parent;
			while (parent && node == parent->left) {
				node = parent;
				parent = parent->parent;
			}
			return parent;
		}
	};
	/*
	INFO Get the range of pairs with keys equal to <key>
	INFO No exception
	*/
	pair<nodePtr, nodePtr> getRange(K key) {
		nodePtr start = searchKey(_root, key);
		if (start) {
			nodePtr end = getSuccessor(start);
			return (make_pair(start, end));
		} else {
			return (make_pair(NULL, NULL));
		}
	};
	/*
	INFO Get the element directly lower than <key>
	INFO No exception
	*/
	nodePtr getLowerBound(K key) {
		return getLowerBoundUtil(_root, key);
	};
	/*
	INFO Utility function for getLowerBound
	INFO No exception
	*/
	nodePtr getLowerBoundUtil(nodePtr start, K key) {
		if (!start || !key) {
			return NULL;
		} else {
			if (key == start->pair.key) {
				return start;
			} else if (key < start->pair.key) {
				start = start->right;
				while (start->left && key < start->left->pair.key) {
					start = start->left;
				}
				return start;
			} else {
				return getLowerBoundUtil(start->right, key);
			}
		}
	};
	/*
	INFO Get the element directly lower than <key> (const)
	INFO No exception
	*/
	nodePtr lower_bound(const K& key) const {
		return getLowerBoundUtil(_root, key);
	}
	/*
	INFO Get the element directly higher or equal to <key>
	INFO No exception
	*/
	nodePtr getUpperBound(K key) {
		return getUpperBoundUtil(_root, key);
	};
	/*
	INFO Utility function for getUpperBound
	INFO No exception
	*/
	nodePtr getUpperBoundUtil(nodePtr start, K key) {
		if (!start || !key) {
			return NULL;
		} else {
			if (key == start->pair.key) {
				return getSuccessor(start);
			} else if (key < start->pair.key) {
				return getUpperBoundUtil(start->right, key);
			} else {
				start = start->left;
				while (start->right && key < start->right->pair.key) {
					start = start->right;
				}
				return start;
			}
		}
	};
	/*
	INFO Get the element directly higher or equal to <key> (const)
	INFO No exception
	*/
	nodePtr upper_bound(const K& key) const {
		return getUpperBoundUtil(_root, key);
	}
};
// !SECTION RBT

};	// namespace ft
// !SECTION namespace ft
#endif