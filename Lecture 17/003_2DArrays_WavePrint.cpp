#include<iostream>

using namespace std;

void wavePrint(int mat[][3], int m, int n) {

	// iterate over the columns

	for (int j = 0; j < n; j++) {

		// print jth the column

		if (j % 2 == 0) {
			// iterate over the rows from top to bottom
			for (int i = 0; i < m; i++) {
				cout << mat[i][j] << " ";
			}
		} else {
			// iterate over the rows from bottom to top
			for (int i = m - 1; i >= 0; i--) {
				cout << mat[i][j] << " ";
			}
		}
	}
}

int main() {

	int mat[][3] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	wavePrint(mat, m, n);

	return 0;
}