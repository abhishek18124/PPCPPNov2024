/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> count the number of paths that exist between src and dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output : 3

*/

#include<iostream>

using namespace std;

int f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {
		return 0;
	}

	// we are within the grid

	if (maze[i][j] == 'X') {
		return 0;
	}

	if (i == m - 1 and j == n - 1) {
		return 1;
	}

	// recursive case

	return f(maze, m, n, i, j + 1) + f(maze, m, n, i + 1, j);

}

int main() {

	char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	cout << f(maze, m, n, 0, 0) << endl;

	return 0;
}