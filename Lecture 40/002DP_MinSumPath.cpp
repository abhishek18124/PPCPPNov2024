/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (m-1, n-1),
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example :
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// time : O(2^(m+n))
// space: O(m+n)

int f(const vector<vector<int>>& grid, int m, int n, int i, int j) {

	// base case

	// if (i == m || j == n) {
	// 	return INT_MAX;
	// }

	if (i == m - 1 and j == n - 1) {

		// f(m-1, n-1) = find the minimum sum path from (m-1, n-1) to (m-1, n-1)

		return grid[i][j];
	}

	// recursive cases

	// f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

	if (i == m - 1) {
		return grid[i][j] + f(grid, m, n, i, j + 1);
	}

	if (j == n - 1) {
		return grid[i][j] + f(grid, m, n, i + 1, j);
	}

	int X = f(grid, m, n, i, j + 1);
	int Y = f(grid, m, n, i + 1, j);

	return grid[i][j] + min(X, Y);
}

// time : O(mn)
// space: mn due to dp[][] + (m+n) due to fn call stack ~ O(mn)

int fTopdown(const vector<vector<int>>& grid, int m, int n, int i, int j,
             vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == m - 1 and j == n - 1) {

		// f(m-1, n-1) = find the minimum sum path from (m-1, n-1) to (m-1, n-1)

		return dp[i][j] = grid[i][j];
	}

	// recursive cases

	// f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

	if (i == m - 1) {
		return dp[i][j] = grid[i][j] + fTopdown(grid, m, n, i, j + 1, dp);
	}

	if (j == n - 1) {
		return dp[i][j] = grid[i][j] + fTopdown(grid, m, n, i + 1, j, dp);
	}

	int X = fTopdown(grid, m, n, i, j + 1, dp);
	int Y = fTopdown(grid, m, n, i + 1, j, dp);

	return dp[i][j] = grid[i][j] + min(X, Y);

}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(const vector<vector<int>>& grid, int m, int n) {

	vector<vector<int>> dp(m, vector<int>(n));

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			// dp[i][j] stores the result of f(i, j) = min sum path from i,jth cell to m-1,n-1th cell
			if (i == m - 1 and j == n - 1) {
				dp[i][j] = grid[i][j];
			} else if (i == m - 1) {
				dp[i][j] = grid[i][j] + dp[i][j + 1];
			} else if (j == n - 1) {
				dp[i][j] = grid[i][j] + dp[i + 1][j];
			} else {
				dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

// time : O(mn)
// space: O(n) due to dp[]

int fBottomUpSpaceOptimised(const vector<vector<int>>& grid, int m, int n) {

	vector<int> dp(n);

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			// dp[i][j] stores the result of f(i, j) = min sum path from i,jth cell to m-1,n-1th cell
			if (i == m - 1 and j == n - 1) {
				dp[j] = grid[i][j];
			} else if (i == m - 1) {
				dp[j] = grid[i][j] + dp[j + 1];
			} else if (j == n - 1) {
				dp[j] = grid[i][j] + dp[j];
			} else {
				dp[j] = grid[i][j] + min(dp[j + 1], dp[j]);
			}
		}
	}

	return dp[0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

int main() {

	vector<vector<int>> grid = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};

	int m = grid.size();
	int n = grid[0].size();

	cout << f(grid, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m, vector<int>(n, -1));

	cout << fTopdown(grid, m, n, 0, 0, dp) << endl;

	cout << fBottomUp(grid, m, n) << endl;

	cout << fBottomUpSpaceOptimised(grid, m, n) << endl;

	return 0;
}