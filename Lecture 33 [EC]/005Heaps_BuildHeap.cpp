/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap in-place.

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

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}





