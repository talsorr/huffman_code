#include "Heap.hpp"

// add an element to the tree
void Heap::enqueue( HNode* newElement) {
	tree.push_back(newElement);
	position = tree.size() - 1;
	fix_up(position);
	count++;
	return;
}

// fix the heap from a specific index up
void Heap::fix_up(const int& position) {
	HNode* temp = nullptr;
	int index = position;
	while ((index > 1) && (tree[index / 2]->weight > tree[index]->weight)) {
		temp = tree[index];
		tree[index] = tree[index / 2];
		tree[index / 2] = temp;
		index = (index / 2);
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
	if (left < count && *tree[left] < *tree[index])
		index = left;
	if (right < count && *tree[right] < *tree[index])
		index = right;
	if (index != position) {
		HNode* temp = tree[index];
		tree[index] = tree[position];
		tree[position] = temp;
		fix_down(index);
	}
}

void Heap::clear() {
	HNode* temp = nullptr;
	while(count >= 1) {
		temp = dequeue();
		delete temp;
	}
	return;
}
