/*

	Constraints :

	0 < n <= 10

*/

#include<iostream>

using namespace std;

void read(int mat[][10], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
}

void print(int mat[][10], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// # swaps = (n^2 - n) / 2
// each swap takes const time
// therefore time complexity is O(n^2)

void transpose(int mat[][10], int n) {

	for (int i = 0; i < n; i++) {
		// iterate over columns of ith row above the main diagonal
		for (int j = i + 1; j < n; j++) {
			swap(mat[i][j], mat[j][i]);
		}
	}

}

int main() {

	int n;
	cin >> n;

	int mat[10][10];

	read(mat, n);

	print(mat, n);

	transpose(mat, n);

	print(mat, n);

	return 0;
}