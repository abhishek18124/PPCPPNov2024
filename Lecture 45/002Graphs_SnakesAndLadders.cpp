/*

Snake and Ladders Game

*/

#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

vector<int> getPath(int u, const vector<int>& par) {

	vector<int> path = {u};

	while (par[u] != -1) {
		u = par[u];
		path.push_back(u);
	}

	reverse(path.begin(), path.end());

	return path;

}

int minDiceThrows(int n,
                  const vector<pair<int, int>>& snakes,
                  const vector<pair<int, int>>& ladders) {

	vector<vector<int>> adj(n + 1); // 0th index is not used

	vector<int> mp(n + 1, 0);

	for (auto [startPos, endPos] : snakes) {
		mp[startPos] = endPos - startPos;
	}


	for (auto [startPos, endPos] : ladders) {
		mp[startPos] = endPos - startPos;
	}

	for (int u = 1; u < n; u++) {

		if (mp[u] != 0) continue; // cell u contains a snake or ladder therefore no need to roll die on cell u

		for (int d = 1; d <= 6; d++) {

			int v = u + d;
			if (v <= n) { // v is part of the board
				// check for a ladder or snake starting at cell v
				v += mp[v]; // mp[v] is +ve if cell v has ladder, mp[v] is -ve if cell v has snake and mp[v] is zero if cell v has neither snake nor ladder
				adj[u].push_back(v);
			}

		}

	}

	int src = 1;

	queue<int> q; // queue is used to track nodes that are visited but not yet explored
	q.push(src);

	vector<bool> vis(n + 1, false); // vis[i] stores if node i is visited or not
	vis[src] = true;

	vector<int> dis(n + 1); // dis[i] stores the length of the shortest path from src to node i
	dis[src] = 0;

	vector<int> par(n + 1); // par[i] stores the parent of node i in the bfs tree
	par[src] = -1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				vis[ngb] = true;
				q.push(ngb);
				dis[ngb] = dis[cur] + 1; // since we are visiting ngb due to cur therefore in the bfs tree cur is the parent of ngb
				par[ngb] = cur;
			}
		}

	}

	vector<int> path = getPath(n, par);
	for (int node : path) {
		cout << node << " ";
	}
	cout << endl;

	return dis[n];


}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {
		{17, 4},
		{20, 6},
		{24, 16},
		{32, 30},
		{34, 12}
	};

	vector<pair<int, int>> ladders = {
		{2, 15},
		{5, 7},
		{9, 27},
		{18, 29},
		{25, 35}
	};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}