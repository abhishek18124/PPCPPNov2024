/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {
	// fix the heap prop. at the node corr. to index i

	int maxIdx = i;
	int leftChildIdx = 2 * i + 1;
	if (leftChildIdx < n and v[leftChildIdx] > v[maxIdx]) {
		maxIdx = leftChildIdx;
	}

	int rightChildIdx = 2 * i + 2;
	if (rightChildIdx < n and v[rightChildIdx] > v[maxIdx]) {
		maxIdx = rightChildIdx;
	}

	if (maxIdx != i) {
		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);
	}

}


int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// time : n + nlogn ~ O(nlogn)
	// space: O(logn) due to fn call stk used during heapify
	// [HW] try to impl. heapify iteratively then space will be O(1)

	// 1. transform arr[] into a maxHeap // O(n)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// 2. convert the maxHeap to a sorted arr[] // O(nlogn)

	int heapsize = n;

	while (heapsize > 1) {
		swap(v[0], v[heapsize - 1]);
		heapsize--;
		heapify(v, heapsize, 0);
	}

	// 3. print the sorted arr[]

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
