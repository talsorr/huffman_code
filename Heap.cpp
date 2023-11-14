#include "Heap.hpp"

// swap 2 nodes
void swapNodes( std::vector<HNode*> root, int val1, int val2) {  // swap two nodes
	HNode* temp = root[val1];
	root[val1] = root[val2];
	root[val2] = temp;
}

// add an element to the tree
void Heap::enqueue( HNode* newElement) { // push in a new node and fix up
	if (position + 1 >= tree.size())
		tree.resize(tree.size() + 1);
	position++;
	tree[position] = newElement;
	count++;
	fix_up(position);
}

// fix the heap from a specific index up
void Heap::fix_up(const int& index) {    // compare nodes and there children to find the correct spot
	int location = index;
	int ancestor;
	while (location >= 2) {
		ancestor = location / 2;
		if (*tree[location] < *tree[ancestor]) {
			swapNodes(tree, location, ancestor);
			location = ancestor;
		}
		else
			break;
	}
}

// remove the smallest element
HNode* Heap::dequeue() {      // Return the last element if more than one
	if (count == 0) 
		return nullptr;
	
	HNode* temp = tree[1];
	swapNodes(tree, 1, position);
	position--;
	count--;
	fix_down(1);
	return temp;
}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int& index) {      // Compare elements and children, swapping when needed
	int location = index;
	int temp;
	int left = 2 * location;
	int right = (2 * location) + 1;
	if (right <= position && *tree[right] < *tree[left])
		temp = right;
	else
		temp = left; 
	if (*tree[temp] < *tree[location]) {
		swapNodes(tree, temp, location);
		location = temp;
	}
}

void Heap::clear() {
	for (int i = 0; i <= position; i++)
		delete tree[i];
	position = 0;
	count = 0;
	tree.resize(2);
}
