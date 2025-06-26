/*

Given an undirected graph, check if there exists a cycle or not.

	e.g.

	3 3

	0 1
	0 2
	1 2

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, int par, const vector<vector<int>>& adj, vector<bool>& vis) {

	vis[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not yet visited
			if (dfs(ngb, cur, adj, vis)) {
				// you've found a cycle in the sub-component of ngb
				// therefore you've found a cycle in the component of cur
				return true;
			}
		} else {
			// ngb is visited
			// check if cur to ngb edge is a backedge or not
			if (ngb != par) {
				// cur to ngb edge is a backedge
				return true;
			}

		}
	}

	return false; // no backedge found in the component

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

	bool flag = false; // assume no cycle is present in the graph
	vector<bool> vis(n, false);

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// check if there is a cycle in the component of node i using dfs
			if (dfs(i, -1, adj, vis)) {
				// you've found a cycle in the component of node i
				// therefore cycle found in the graph
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "no cycle found" << endl;
	}

	return 0;
}