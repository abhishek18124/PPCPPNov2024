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

	bool flag = false; // assume 't' is not present

	int i;

	// time : nc ~ O(n)
	// space: O(1)

	for (i = 0; i < n; i++) {

		if (arr[i] == t) {

			// you've found the 1st occ. of the 't' at index i

			cout << i << endl;
			flag = true;

		}

	}

	if (flag == false) {
		cout << -1 << endl;

	}

	return 0;
}