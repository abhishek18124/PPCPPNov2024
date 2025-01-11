#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int k = 3;

	// time : O(kn)

	for (int j = 1; j <= k; j++) {
		for (int i = n - 1; i >= 1; i--) { // logic to rotate array once
			swap(arr[i], arr[i - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}