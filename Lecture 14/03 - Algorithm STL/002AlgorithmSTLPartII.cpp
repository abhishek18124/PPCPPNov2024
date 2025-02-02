#include<iostream>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool comparator(int a, int b) {

	// if (a > b) {
	// 	return true;
	// }

	// return false;

	return a > b;

}

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// 1. using a customer comparator

	sort(arr, arr + n, comparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 2. using greater<T>() function object / functor

	int brr[] = {50, 10, 20, 40, 30};
	int m = sizeof(brr) / sizeof(int);

	sort(brr, brr + m, greater<int>());

	for (int i = 0; i < m; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	return 0;
}
