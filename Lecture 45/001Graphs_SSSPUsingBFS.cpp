/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

9 12

0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int src = 0;

	queue<int> q; // queue is used to track nodes that are visited but not yet explored
	q.push(src);

	vector<bool> vis(n, false); // vis[i] stores if node i is visited or not
	vis[src] = true;

	vector<int> dis(n); // dis[i] stores the length of the shortest path from src to node i
	dis[src] = 0;

	vector<int> par(n); // par[i] stores the parent of node i in the bfs tree
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

	for (int i = 0; i < n; i++) {
		cout << "dis[" << i << "] = " << dis[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "par[" << i << "] = " << par[i] << endl;
	}

	cout << endl;

	for (int i = 1; i < n; i++) {
		cout << "dis[" << i << "] = " << dis[i] << " : ";
		vector<int> path = getPath(i, par);
		for (int node : path) {
			cout << node << " ";
		}
		cout << endl;
	}


	return 0;
}