#include<iostream>

using namespace std;

bool isSorted(int X[], int n, int i) {
	// base case
	if (i == n - 1) {
		// check if X[n-1...n-1] = {X[n-1]}
		return true;
	}

	// recursive case

	// f(i) = check if X[i..n-1] is sorted or not

	return X[i] < X[i + 1] and isSorted(X, n, i + 1);

}

int main() {

	int X[] = {10, 20, 30, 40, 50};
	int n = sizeof(X) / sizeof(int);

	isSorted(X, n, 0) ? cout << "sorted" << endl : cout << "not sorted" << endl;

	return 0;
}