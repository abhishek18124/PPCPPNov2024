// constraints : n <= 100

#include<iostream>

using namespace std;

// time : O(n)
// space: O(n) due to x[]

int maximumSubarraySumUsingKadanes(int arr[], int n) {

	int x[100]; // based on constraints

	x[0] = arr[0];
	int maxSoFar = x[0];

	for (int i = 1; i < n; i++) {
		x[i] = max(x[i - 1] + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x[i]);
	}

	return maxSoFar;

}

// time : O(n)
// space: O(1)

int maximumSubarraySumUsingKadanesSpaceOptimised(int arr[], int n) {

	int x = arr[0]; // x stores x[0]
	int maxSoFar = x;

	for (int i = 1; i < n; i++) {
		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);
	}

	return maxSoFar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySumUsingKadanes(arr, n) << endl;
	cout << maximumSubarraySumUsingKadanesSpaceOptimised(arr, n) << endl;

	return 0;
}