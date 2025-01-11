// 1 <= n <= 1000

#include<iostream>

using namespace std;

int main() {

	int arr[1000]; // based on constraints

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	int i = 0;
	int j = n - 1;

	while (i < j) { // steps = n/2 // time = n/2.c ~ O(n) space = O(1)

		swap(arr[i], arr[j]);
		i++;
		j--;

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}