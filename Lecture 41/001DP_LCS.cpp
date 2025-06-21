/*

Given two strings s1 and s2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ATGC", s2 = "AGCT"
	Output: 3
	Explanation : "AGC" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

int f(const string& s1, const string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {
		return 1 + f(s1, s2, m, n, i + 1, j + 1);
	}

	return max(f(s1, s2, m, n, i + 1, j),
	           f(s1, s2, m, n, i, j + 1));

}

// time : (m+1)x(n+1).const ~ O(mn)
// space: (m+1)x(n+1) for dp[][] + (m+n) for fn call stack ~ O(mn)

int fTopdown(const string& s1,
             const string& s2,
             int m, int n,
             int i, int j,
             vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		// you've solved f(i, j) previously therefore we can reuse the result
		return dp[i][j];
	}

	// base case

	if (i == m || j == n) {
		return dp[i][j] = 0;
	}

	// recursive case

	// f(i, j) = find the length of the longest common subsequence b/w
	// s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + fTopdown(s1, s2, m, n, i + 1, j + 1, dp);
	}

	return dp[i][j] = max(fTopdown(s1, s2, m, n, i + 1, j, dp),
	                      fTopdown(s1, s2, m, n, i, j + 1, dp));

}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(const string& s1, const string& s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// 0-init of dp[][] makes sure that base cases is auto. handled

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			// dp[i][j] = f(i, j) = len of the LCS(s1[i...m-1], s2[j...n-1])
			if (s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;

	string ans = "";

	int i = 0;
	int j = 0;

	while (!(i == m || j == n)) {

		if (s1[i] == s2[j]) {
			ans += s1[i]; // s2[j]
			i++;
			j++;
		} else if (dp[i][j] == dp[i][j + 1]) {
			j++;
		} else {
			i++;
		}

	}

	cout << ans << endl;

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

int main() {

	string s1("ATGC");
	string s2("AGCT");

	int m = s1.size();
	int n = s2.size();

	cout << f(s1, s2, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << fTopdown(s1, s2, m, n, 0, 0, dp) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	return 0;
}