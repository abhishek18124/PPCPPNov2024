#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) {

	// iterate over the n-1 passes

	for (int i = 1; i <= n - 1; i++) {

		// in the ith pass, place the largest value in the
		// unsorted part of the arr[] to its correct position

		for (int j = 0; j < n - i; j++) {

			if (arr[j] > arr[j + 1]) {

				swap(arr[j], arr[j + 1]);

			}

		}

	}

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}