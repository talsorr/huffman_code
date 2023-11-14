#include "Heap.hpp"

// swap 2 nodes
void swapNodes( HNode* node1, HNode* node2) {
	HNode temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

// add an element to the tree
void Heap::enqueue( HNode* newElement) {
	tree.push_back(0);
	position = tree.size() - 1;
	fix_up(position);
	tree[position] = newElement;
}

// fix the heap from a specific index up
void Heap::fix_up(const int& index) {
	position = index;
	while ((position > 1) && (tree[position] < tree[(position - 1) / 2])) {
		tree[position] = tree[(position - 1) / 2]; 
	}
	return;
}

// remove the smallest element
HNode* Heap::dequeue() {
	HNode* temp = tree[0];
	tree[0] = tree[tree.size() - 1];
	count--;
	fix_down(0);
	return temp;
}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int& position) {
	int index = position;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < count && tree[left]->weight < tree[index]->weight)
		index = left;
	if (right < count && tree[right]->weight < tree[index]->weight)
		index = right;
	if (index != position) {
		swapNodes(tree[index], tree[position]);
		fix_down(index);
	}
}

void Heap::clear() {
	HNode* temp = nullptr;    // Dequeue all nodes from the heap and delete them
	while(count >= 1) {
		temp = dequeue();
		delete temp;
	}
	return;
}
