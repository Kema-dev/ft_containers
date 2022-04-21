#ifndef MAP_HPP
#define MAP_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "../Tools/Exceptions.hpp"
#include "../Tools/Node.hpp"

namespace ft {

// SECTION map
template <class K, class V, class Compare = ft::less<K>, class Allocator = std::allocator<ft::pair<const K, V> > >
class map {
   public:
	typedef ft::node<const K, V>* nodePtr;
	typedef ft::node<const K, V>& nodeRef;
	typedef ft::node<const K, V> nodeType;
	typedef ft::pair<const K, V> pairType;
	typedef ft::pair<const K, V>& pairRef;
	typedef ft::pair<const K, V>* pairPtr;

	typedef K key_type;
	typedef V value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef value_type* value_pointer;
	typedef value_type& value_reference;
	typedef const value_type* const_value_pointer;
	typedef const value_type& const_value_reference;
	typedef Allocator allocator_type;
	typedef Compare key_compare;

	class MapIterator {
	   public:
		MapIterator(nodePtr ptr) : ptr(ptr) {}
		MapIterator(const MapIterator& other) : ptr(other.ptr) {}
		MapIterator& operator=(const MapIterator& other) {
			ptr = other.ptr;
			return *this;
		}
		MapIterator& operator++() {
			ptr = ptr->getSuccessor();
			return *this;
		}
		MapIterator operator++(int) {
			MapIterator tmp(*this);
			ptr = ptr->getSuccessor();
			return tmp;
		}
		MapIterator& operator--() {
			ptr = ptr->getPredecessor();
			return *this;
		}
		MapIterator operator--(int) {
			MapIterator tmp(*this);
			ptr = ptr->getPredecessor();
			return tmp;
		}
		bool operator==(const MapIterator& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const MapIterator& other) const {
			return ptr != other.ptr;
		}
		value_type& operator*() {
			return ptr->pair;
		}
		value_type* operator->() {
			return &(ptr->pair);
		}

	   private:
		nodePtr ptr;
	};

	class MapReverseIterator {
	   public:
		MapReverseIterator(nodePtr ptr) : ptr(ptr) {}
		MapReverseIterator(const MapReverseIterator& other) : ptr(other.ptr) {}
		MapReverseIterator& operator=(const MapReverseIterator& other) {
			ptr = other.ptr;
			return *this;
		}
		MapReverseIterator& operator++() {
			ptr = ptr->getPredecessor();
			return *this;
		}
		MapReverseIterator operator++(int) {
			MapReverseIterator tmp(*this);
			ptr = ptr->getPredecessor();
			return tmp;
		}
		MapReverseIterator& operator--() {
			ptr = ptr->getSuccessor();
			return *this;
		}
		MapReverseIterator operator--(int) {
			MapReverseIterator tmp(*this);
			ptr = ptr->getSuccessor();
			return tmp;
		}
		bool operator==(const MapReverseIterator& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const MapReverseIterator& other) const {
			return ptr != other.ptr;
		}
		value_type& operator*() {
			return ptr->pair;
		}
		value_type* operator->() {
			return &(ptr->pair);
		}

	   private:
		nodePtr ptr;
	};

	typedef MapIterator iterator;
	typedef MapIterator const_iterator;
	typedef MapReverseIterator reverse_iterator;
	typedef MapReverseIterator const_reverse_iterator;

	class value_compare {
	   public:
		bool operator()(const value_type& lhs, const value_type& rhs) const {
			return comp(lhs.first, rhs.first);
		}
		value_compare(Compare comp) : comp(comp) {}

	   private:
		Compare comp;
	};

   private:
	nodePtr _root;
	size_type _size;
	allocator_type _alloc;
	value_compare _comp;

   public:
	// SECTION Constructors / Destructors
	// INFO Create an map tree with a custom allocator and comparator
	map(const allocator_type& alloc = Allocator(), const Compare& comp = Compare())
		: _root(NULL), _size(0), _alloc(alloc), _comp(comp){};
	// INFO Create a map filled with a range of elements
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		const Compare& comp = Compare())
		: _root(NULL), _size(0), _alloc(alloc), _comp(comp) {
		insert(first, last);
	}
	// INFO Copy <other>
	map(const map& other)
		: _root(NULL), _size(0), _alloc(other._alloc), _comp(other._comp) {
		insert(other.begin(), other.end());
		_root->color = black;
	}
	/*
	INFO Create a tree with root node containing pair <dpair>
	INFO Can throw exception (self: allocFail)
	*/
	map(pairType dpair) {
		_root = standaloneNode(dpair);
		_root->color = black;
		_size = 1;
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
		delete node;
		_size--;
	};
	// INFO Clear the tree (fully)
	void clear(void) {
		clear(_root);
		_root = NULL;
		_size = 0;
	};
	/*
	INFO Clear the entire tree
	INFO No exception
	*/
	~map(void) {
		clear(_root);
	};
	/*
	INFO Make map <this> become a copy of map <rhs>
	INFO Can throw exception (calls)
	*/
	map& operator=(map const& rhs) {
		if (this != &rhs) {
			clear(_root);
			insert(rhs.begin(), rhs.end());
			_root->color = black;
		}
		return *this;
	};
	// INFO Get the allocator
	allocator_type get_allocator(void) const {
		return _alloc;
	};
	/*
	INFO Create a map with map <src> as "root"
	INFO Can throw exception (calls)
	*/
	// !SECTION Constructors / Destructors
	// SECTION Operators and basic functions
	// INFO Get the root node
	nodePtr getRoot(void) const {
		return _root;
	};
	// INFO access specified element with bounds checking
	value_reference at(const key_type& key) {
		nodePtr node = find(key);
		if (!node)
			throw std::out_of_range("map::at");
		return node->pair.second;
	};
	// INFO access or insert specified element
	value_reference operator[](const key_type& key) {
		nodePtr node = find(key);
		if (!node) {
			node = insert(value_type(key, V())).first;
		}
		return node->pair.second;
	};
	// INFO Get the first element as an iterator
	iterator begin(void) {
		return iterator(_root);
	};
	// INFO Get the first element as a const_iterator
	const_iterator begin(void) const {
		return const_iterator(_root);
	};
	// INFO Get the last element as an iterator
	iterator end(void) {
		return iterator(NULL);
	};
	// INFO Get the last element as a const_iterator
	const_iterator end(void) const {
		return const_iterator(NULL);
	};
	// INFO Get the first element as a reverse_iterator
	reverse_iterator rbegin(void) {
		return reverse_iterator(_root);
	};
	// INFO Get the first element as a const_reverse_iterator
	const_reverse_iterator rbegin(void) const {
		return const_reverse_iterator(_root);
	};
	// INFO Get the last element as a reverse_iterator
	reverse_iterator rend(void) {
		return reverse_iterator(NULL);
	};
	// INFO Get the last element as a const_reverse_iterator
	const_reverse_iterator rend(void) const {
		return const_reverse_iterator(NULL);
	};
	// INFO Check if the map is empty
	bool empty(void) const {
		return _size == 0;
	};
	// INFO Get the size of the map
	size_type size(void) const {
		return _size;
	};
	// INFO Get the maximum size of the map
	size_type max_size(void) const {
		return size_type(-1);
	};
	// INFO erase the element at position <pos>
	iterator erase(iterator pos) {
		remove(pos.ptr);
	};
	// INFO erase the elements in the range [<first>, <last>)
	iterator erase(iterator first, iterator last) {
		while (first != last)
			erase(first++);
	};
	// INFO erase the element with key <key>
	size_type erase(const key_type& key) {
		nodePtr node = find(key);
		if (!node)
			return 0;
		remove(node);
		return 1;
	};
	// INFO swap the contents of <this> and <other>
	void swap(map& other) {
		std::swap(_root, other._root);
		std::swap(_size, other._size);
		std::swap(_alloc, other._alloc);
		std::swap(_comp, other._comp);
	};
	// INFO Count the number of elements with key <key>
	size_type count(const key_type& key) const {
		return find(key) ? 1 : 0;
	};
	// INFO Find the first element with key <key>
	iterator find(const key_type& key) {
		return iterator(searchKey(key));
	};
	// INFO Get the range of elements with key <key>
	std::pair<iterator, iterator> equal_range(const key_type& key) {
		nodePtr node = searchKey(key);
		if (!node)
			return ft::pair<iterator, iterator>(end(), end());
		return ft::pair<iterator, iterator>(iterator(node), iterator(node + 1));
	};
	// INFO Get the range of elements with key <key>
	std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
		nodePtr node = searchKey(key);
		if (!node)
			return ft::pair<const_iterator, const_iterator>(end(), end());
		return ft::pair<const_iterator, const_iterator>(const_iterator(node), const_iterator(node + 1));
	};
	// INFO Get the lower bound of the elements with key <key> (the first element with key >= <key>)
	iterator lower_bound(const key_type& key) {
		nodePtr start = _root;
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
	// INFO Get the lower bound of the elements with key <key> (the first element with key >= <key>)
	const_iterator lower_bound(const key_type& key) const {
		nodePtr start = _root;
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
	// INFO Get the upper bound of the elements with key <key> (the first element with key < <key>)
	iterator upper_bound(const key_type& key) {
		nodePtr start = _root;
		if (!start || !key) {
			return NULL;
		} else {
			if (key == start->pair.key) {
				return start;
			} else if (key < start->pair.key) {
				return start;
			} else {
				start = start->right;
				while (start->left && key < start->left->pair.key) {
					start = start->left;
				}
				return start;
			}
		}
	};
	// INFO Get the upper bound of the elements with key <key> (the first element with key < <key>)
	const_iterator upper_bound(const key_type& key) const {
		nodePtr start = _root;
		if (!start || !key) {
			return NULL;
		} else {
			if (key == start->pair.key) {
				return start;
			} else if (key < start->pair.key) {
				return start;
			} else {
				start = start->right;
				while (start->left && key < start->left->pair.key) {
					start = start->left;
				}
				return start;
			}
		}
	};
	// INFO Get the comparison object
	key_compare key_comp(void) const {
		return _comp;
	};
	// INFO Get the value comparison object
	value_compare value_comp(void) const {
		return _comp;
	};
	/*
	INFO Get a mint new node with pair <dpair>
	INFO Can throw exception (self: allocFail)
	*/
	nodePtr standaloneNode(pairType dpair) const {
		nodePtr buf = new nodeType(dpair);
		if (!buf) {
			throw allocFail();
		}
		return buf;
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
	// !SECTION Operators and basic functions
	// SECTION Insertion
	/*
	INFO /!\ DO NOT USE /!\ (Use "add" instead)
	INFO Can throw exception (calls)
	*/
	nodePtr add(pairType dpair) {
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
	INFO Add pair <dpair> to the tree
	INFO Can throw exception (calls)
	*/
	nodePtr insert(pairType dpair) {
		nodePtr newNode = add(dpair);
		fixInsert(newNode);
		return newNode;
	};
	/*
	INFO Add a new node with pair <dpair> to the tree
	INFO Can throw exception (calls)
	*/
	nodePtr insert(const K& key, const V& value) {
		pairType dpair = ft::make_pair(key, value);
		nodePtr newNode = add(dpair);
		fixInsert(newNode);
		return newNode;
	};
	/*
	INFO Fix the map after insertion of nodePtr <node>
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
	INFO Fix the map after deletion of nodePtr <node>
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
	ft::pair<nodePtr, nodePtr> getRange(K key) {
		nodePtr start = searchKey(_root, key);
		if (start) {
			nodePtr end = getSuccessor(start);
			return (make_pair(start, end));
		} else {
			return (make_pair(NULL, NULL));
		}
	};
};
// !SECTION map
}  // namespace ft
// !SECTION namespace ft
#endif