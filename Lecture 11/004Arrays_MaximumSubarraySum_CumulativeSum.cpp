// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	int csum[101]; // based on constraints
	csum[0] = 0;

	for (int i = 1; i <= n; i++) { // n-steps
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << csum[i] << " ";
	// }

	// cout << endl;

	int maxSoFar = INT_MIN; // to store the maximum subarray sum

	// iterate over the subarrays

	for (int i = 0; i <= n - 1; i++) { // n^2 steps

		for (int j = i; j <= n - 1; j++) {

			// find the sum of the subarray that starts at the ith index and ends at the jth index

			int sum = csum[j + 1] - csum[i];
			maxSoFar = max(maxSoFar, sum);

		}

	}

	// total steps = n + n^2 ~ O(n^2)
	// space = O(n) due to csum[]

	return 0;
}