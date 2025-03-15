#include<iostream>

using namespace std;

// time : O(logn) space : O(logn) due to fn call stk

int f(int arr[], int s, int e, int t) {

	// base case
	if (s > e) {
		// search space is empty
		return -1;
	}

	// recursive case

	// f(s, e) : find the idx of 't' in sorted arr[s...e] using binary search

	int m = s + (e - s) / 2;
	if (arr[m] == t) {
		return m;
	} else if (t > arr[m]) {
		// recursively, find the idx of the 't' in sorted arr[m+1...e]
		return f(arr, m + 1, e, t);
	} else {
		// t < arr[m]
		// recursively, find the idx of the 't' in the sorted arr[s...m-1]
		return f(arr, s, m - 1, t);
	}

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);
	int t = 10;

	cout << f(arr, 0, n - 1, t) << endl;

	return 0;
}