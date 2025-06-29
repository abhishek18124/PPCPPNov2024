// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// 2. multi-source bfs - time : O(mn)

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dis(m, vector<int>(n, -1)); // dis[i][j] -1 means i,jth vertex is not yet visited

	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// (i, j)th cell corresponds to a source vertex
				q.push({i, j});
				dis[i][j] = 0;
			}
		}
	}

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	while (!q.empty()) {

		// pair<int, int> p = q.front();
		// q.pop();
		// int i = p.first;
		// int j = p.second;

		auto [i, j] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {

			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and dis[nx][ny] == -1) {
				dis[nx][ny] = dis[i][j] + 1;
				q.push({nx, ny});
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