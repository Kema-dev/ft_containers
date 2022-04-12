#ifndef FT_CONTAINERS_RBT_HPP
#define FT_CONTAINERS_RBT_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "KVP.hpp"

enum e_color {
	black,
	red
};
enum e_branch {
	left,
	right
};

using namespace std;

namespace ft {
template <typename K, typename V>
struct node {
	ft::kvp<K, V> pair;
	e_color color;
	node *parent;
	node *left;
	node *right;
	//	*	Node constructors
	node(kvp<K, V> &dpair)
		: pair(dpair), color(red), parent(NULL), left(NULL), right(NULL) {
	}
	//	*	Node destructor
	~node(){};
};
//	*	RBT
template <typename K, typename V>
class RBT {
   public:
	//	*	Typedefinition
	typedef node<K, V> *nodePtr;

   private:
	nodePtr _root;

   public:
	//	*	Swap
	void swap(RBT &src) {
		nodePtr bufRoot = _root;
		_root = src._root;
		src._root = bufRoot;
	}

   public:
	//	*	Constructors
	RBT(void)
		: _root(NULL){};
	RBT(ft::kvp<K, V> pair)
		: _root(allocator<nodePtr>(1)) {
		allocator<nodePtr>(construct(_root, node<K, V>(pair)));
	};
	RBT(RBT const &src)
		: _root(NULL) {
		*this = src;
		_root->color = black;
	};
	//	*	Destructor and associated function
	void clear(nodePtr _root) {
		if (!_root)
			return;
		clear(_root->left);
		clear(_root->right);
		delete (_root);	 // TODO ANCHOR Check if delete is ok
	};
	~RBT(void) {
		clear(_root);
	};
	//	*	Getters / Setters
	nodePtr getRoot(void) const {
		return _root;
	};
	//	*	Other member functions
	RBT &operator=(RBT const &rhs) {
		clear(_root);
		copy(rhs._root);
		return *this;
	};
	nodePtr copy(nodePtr node) {
		if (!node)
			return NULL;
		// this->getRoot()->pair = insert(node->pair);
		// this->getRoot()->color = copy(node->color);
		// this->getRoot()->parent = copy(node->parent);
		// this->getRoot()->left = copy(node->left);
		// this->getRoot()->right = copy(node->right);
		// return this;
		// TODO ANCHOR copy
		return NULL;
	};
	nodePtr insert(ft::kvp<K, V> dpair) {
		if (!_root)
			_root = insert(_root, standaloneNode(dpair));
		else
			insert(_root, standaloneNode(dpair));
		return _root;
	}
	nodePtr insert(nodePtr start, nodePtr leaf) {
		if (!leaf) {
			return NULL;
		}
		if (!start) {
			start = leaf;
			start->color = black;
			return leaf;
		}
		if ((ft::less(start->pair, leaf->pair)) == true) {
			if (!start->left) {
				leaf->color = red;
				leaf->parent = start;
				start->left = leaf;
				checkTree(leaf);
			} else {
				insert(start->left, leaf);
			}
		} else {
			if (!start->right) {
				leaf->color = red;
				leaf->parent = start;
				start->right = leaf;
				checkTree(leaf);
			} else {
				insert(start->right, leaf);
			}
		}
		return (leaf);
	};
	nodePtr standaloneNode(ft::kvp<K, V> dpair) const {
		return new node<K, V>(dpair);
	};
	//	*	Searching functions
	nodePtr searchKey(K key) {
		return (searchKey(_root, key));
	};
	nodePtr searchKey(nodePtr start, K key) {
		if (!start || !key) {
			return NULL;
		} else {
			if (key == start->key) {
				return start;
			} else if (ft::less(key, start->key) == true) {
				return searchKey(start->left, key);
			} else {
				return searchKey(start->right, key);
			}
		}
	};
	//	*	Printing functions
	void setColor(nodePtr node) {
		if (node->color == red)
			cout << "\e[31m";
		else if (node->color == black)
			cout << "\e[30m";
	};
	void unsetColor(void) {
		cout << "\e[39m";
	};
	void print(const string &prefix, const nodePtr node, bool isLeft) {
		if (node != nullptr) {
			cout << prefix;
			cout << (isLeft ? "├──" : "└──");
			setColor(node);
			cout << node->pair.key << ":" << node->pair.value << endl;
			unsetColor();
			print(prefix + (isLeft ? "│   " : "    "), node->left, true);
			print(prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}
	//	*	Checking and repairing functions
	void checkTree(nodePtr node) {
		if (node->parent->color == red) {
			if (_root)
				recolor_tree(_root);
		}
		node->color = red;
	};
	void recolor_tree(nodePtr node) {
		if (node) {
			if (node->color == red)
				node->color = black;
			else
				node->color = red;
			recolor_tree(node->left);
			recolor_tree(node->right);
		}
	};
};
};	// namespace ft
#endif