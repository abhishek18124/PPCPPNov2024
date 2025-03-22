/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> check if there exists a path from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

int cnt = 0; // to track no. of valid paths from 0,0 to m-1,n-1

bool f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (maze[i][j] == 'X') {
		return false;
	}

	if (i == m - 1 and j == n - 1) { // order of base cases is imp. here, as it is possible destn might be blocked
		cnt++;
		return true;
	}

	// recursive case

	// f(i, j) = check if there exists a path from the (i, j)th cell to (m-1, n-1)th cell ?

	// maze[i][j] != 'X' => true

	if (i == m - 1) {
		return f(maze, m, n, i, j + 1);
	}

	if (j == n - 1) {
		return f(maze, m, n, i + 1, j);
	}

	bool x = f(maze, m, n, i, j + 1);
	bool y = f(maze, m, n, i + 1, j);

	return x or y;

	// return f(maze, m, n, i, j + 1) or f(maze, m, n, i + 1, j);

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

	f(maze, m, n, 0, 0) ? cout << "path found" << endl :
	                           cout << "path not found" << endl;

	cout << cnt << endl;

	return 0;
}