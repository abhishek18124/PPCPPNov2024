/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>
#define vvvi vector<vector<vector<int>>>

using namespace std;

int f(const vector<int>& p, int i, int j, int y) {

	// base case

	if (i == j) { // y == p.size()
		return y * p[i]; // y * [j]
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell ith bottle in the yth year

	// option 2 : sell jth bottle in the yth year

	return max(y * p[i] + f(p, i + 1, j, y + 1),
	           y * p[j] + f(p, i, j - 1, y + 1));

}

// time : O(n^2)
// space: O(n^2)

int fTopdown(const vector<int>& p, int i, int j, vector<vector<int>>& dp) {

	// lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int y = p.size() - j + i;

	// base case

	if (i == j) { // y == p.size()
		return dp[i][j] = y * p[i]; // y * [j]
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell ith bottle in the yth year

	// option 2 : sell jth bottle in the yth year

	return  dp[i][j] = max(y * p[i] + fTopdown(p, i + 1, j, dp),
	                       y * p[j] + fTopdown(p, i, j - 1, dp));

}

// time : O(n^2)
// space: O(n^2)

// HW : optimise space from 2d vec to 1d vec i.e. O(n^2) to O(n)

int fBottomUp(const vector<int>& p, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		// int j = i;
		// int y = n;
		// dp[i][j] = y * p[i];
		dp[i][i] = n * p[i];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j <= n - 1; j++) {
			// dp[i][j] stores the result of f(i, j)

			// decide for the yth year
			int y = n - j + i;

			// option 1 : sell the ith bottle in yth year
			// option 2 : sell the jth bottle in yth year

			dp[i][j] = max(y * p[i] + dp[i + 1][j],
			               y * p[j] + dp[i][j - 1]);
		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index we store f(0, n-1)

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	vector<vector<int>> dp(n, vector<int>(n, -1));

	cout << fTopdown(p, 0, n - 1, dp) << endl;

	cout << fBottomUp(p, n) << endl;

	return 0;
}