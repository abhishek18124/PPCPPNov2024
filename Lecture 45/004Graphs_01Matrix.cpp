// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// 1. brute-force approach - time : mn.mn ~ O(m^2n^2)

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						dis[ii][jj] = min(dis[ii][jj],
						                  abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return dis;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	vector<vector<int>> dis = updateMatrix(mat);

	int m = dis.size();
	int n = dis[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}