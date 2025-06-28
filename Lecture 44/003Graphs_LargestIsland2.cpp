#include<iostream>
#include<vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dfs(const vector<vector<int>>& grid,
        vector<vector<bool>>& vis,
        int m, int n,
        int i, int j) {

	// mark the (i, j)th vertex as visited

	vis[i][j] = true;

	// find the size of the component that contains the (i, j)th vertex

	int cnt = 1; // to track the count of vertices in the current component

	// visit the unvisited neighbours of the (i, j)th vertex

	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			cnt += dfs(grid, vis, m, n, nx, ny);
		}
	}

	return cnt;

}

int largestIsland(vector<vector<int>> grid, int m, int n) {

	vector<vector<bool>> vis(m, vector<bool>(n, false)); // to keep track of visited vertices
	int maxAreaSoFar = 0; // to keep track of the area of the largest island

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1 and !vis[i][j]) {
				maxAreaSoFar = max(maxAreaSoFar,
				                   dfs(grid, vis, m, n, i, j));
			}
		}
	}

	return maxAreaSoFar;
}

int main() {

	vector<vector<int>> grid = {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};

	int m = grid.size();
	int n = grid[0].size();

	cout << largestIsland(grid, m, n) << endl;

	return 0;
}