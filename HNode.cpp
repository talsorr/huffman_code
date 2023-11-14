// hnode.cpp -- heap node class
// c. 2015 A. Deeter

#include "HNode.hpp"

// constructor for leaf nodes
HNode::HNode(const char& s, const int& t) {
	value = s;
	weight = t;
	left = nullptr;
	right = nullptr;
}

// constructor for internal nodes
HNode::HNode(HNode* l, HNode* r) {
	weight = (l->weight + r->weight);
	left = l;
	right = r;
}
