// n <= 1000

#include<iostream>

using namespace std;

int main() {

	int arr[1000]; // based on constraints

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int t;
	cin >> t;

	int i;

	// time : nc ~ O(n)
	// space: O(1)

	for (i = n - 1; i >= 0; i--) {

		if (arr[i] == t) {

			// you've found the last occ. of the 't' at index i

			cout << i << endl;
			break;

		}

	}

	if (i == -1) {
		// 't' is not found in the arr[]
		cout << -1 << endl;

	}

	return 0;
}