// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);

	int k = 3; // denotes the maximum element in the array

	int freq[10] = {0}; // based on constraints

	for (int i = 0; i < n; i++) { // linear time

		int x = arr[i];
		freq[x]++;

	}

	// for (int i = 0; i <= k; i++) {
	// 	cout << "freq[" << i << "] = " << freq[i] << endl;
	// }

	for (int i = 0; i <= k; i++) { // linear time

		int x = freq[i];

		// print i, x times

		while (x--) {
			cout << i << " ";
		}

		// for (int j = 1; j <= x; j++) {
		// 	cout << i << " ";
		// }

	}

	// total steps = n + n
	// work done in each step = const
	// total time ~ O(n)

	// total space = k + 1 ~ O(k) due to freq[]

	return 0;
}