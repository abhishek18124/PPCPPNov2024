// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {
	int j = s; // to iterate over arr[s..e-1]
	int i = s - 1; // to repr. the boundary of left partition
	int pivot = arr[e];
	while (j < e) {
		if (arr[j] < pivot) {
			// you want arr[j] to be in the left partition
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	swap(arr[e], arr[i + 1]); // pivot is now at its correct position
	return i + 1; // pivot's index
}

void quickSort(int arr[], int s, int e) {
	// base case

	if (s > e) { // mandatory
		return;
	}

	if (s == e) { // optional, but still write it to avoid unnecessary rec. calls
		return;
	}

	// recursive case

	// f(s, e) = sort arr[s...e] using quickSort

	// 1. partition arr[s...e] around the pivot i.e. arr[e]
	int pidx = partition(arr, s, e);

	// 2. quickSort arr[s...pidx-1] and arr[pidx+1...e]
	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}