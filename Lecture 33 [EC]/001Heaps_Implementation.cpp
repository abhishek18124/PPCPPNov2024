/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v;

	void heapify(int i) {
		// fix the heap prop. at the node corr. to index i

		int minIdx = i;
		int leftChildIdx = 2 * i + 1;
		if (leftChildIdx < v.size() and v[leftChildIdx] < v[minIdx]) {
			minIdx = leftChildIdx;
		}

		int rightChildIdx = 2 * i + 2;
		if (rightChildIdx < v.size() and v[rightChildIdx] < v[minIdx]) {
			minIdx = rightChildIdx;
		}

		if (minIdx != i) {
			swap(v[i], v[minIdx]);
			heapify(minIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx = v.size() - 1;
		int parentIdx = childIdx % 2 == 1 ? childIdx / 2 : childIdx / 2 - 1;
		while (childIdx != 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 1 ? childIdx / 2 : childIdx / 2 - 1;
		}
	}

	void pop() {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		heapify(0); // fixes the heap prop. at index 0 ie. root node which
		// may have been violated due to swap
	}

	int top() { // time : O(1)
		return v[0];
	}

	int size() { // time : O(1)
		return v.size();
	}

	bool empty() { // time : O(1)
		return v.empty();
	}

};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}



