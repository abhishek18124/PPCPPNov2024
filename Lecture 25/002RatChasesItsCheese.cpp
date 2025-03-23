#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
}

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n || i == -1 || j == -1) { // you've gone outside the grid
		return;
	}

	if (maze[i][j] == 'X') { // you've reached a blocked cell
		return;
	}

	if (i == m - 1 and j == n - 1) { // you've reached the destn i.e. you've found a path
		path[i][j] = '1';
		printPath(path, m, n);
		path[i][j] = '0';
		cout << endl;
		return;
	}

	// recursive case

	// if (path[i][j] == '1') {
	// 	// i,jth cell is already part of the path under-const
	// 	// so no need to take decision for it again
	// 	return;
	// }

	path[i][j] = '1';
	maze[i][j] = 'X';
	f(maze, path, m, n, i, j + 1);
	f(maze, path, m, n, i, j - 1);
	f(maze, path, m, n, i + 1, j);
	f(maze, path, m, n, i - 1, j);
	path[i][j] = '0'; // backtracking
	maze[i][j] = '0'; // backtracking

}

int main() {

	char maze[][10] = {
		"0X00",
		"000X",
		"X0X0",
		"X00X",
		"XX00"
	};

	char path[][10] = {
		"0000",
		"0000",
		"0000",
		"0000",
		"0000"
	};

	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}
