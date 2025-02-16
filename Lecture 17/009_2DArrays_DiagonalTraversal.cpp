/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal of the mat[][] that starts at index i,j

	int diagonalLen = min(m - i, n - j);

	for (int k = 0; k < diagonalLen; k++) {
		cout << mat[i + k][j + k] << " ";
	}

	cout << endl;

}

void diagonalTraversal(int mat[][10], int m, int n) {

	// iterate over starting points of all the diagonals

	// (0, j)

	for (int j = 0; j < n; j++) { // print diagonals that start at (0, j)

		printDiagonal(mat, m, n, 0, j);

	}

	// (i, 0)

	for (int i = 1; i < m; i++) { // print diagonals that start at (i, 0)

		printDiagonal(mat, m, n, i, 0);

	}

}

int main() {

	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	diagonalTraversal(mat, m, n);

	return 0;
}