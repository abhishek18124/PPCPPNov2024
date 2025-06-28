/*

Given an undirected graph, check if it is bipartite or not.

	e.g.

	5 5

	0 1
	0 2
	1 3
	2 4
	3 4

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool dfs(int cur, const vector<vector<int>>& adj, vector<int>& cm, int c) {

	cm[cur] = c;

	for (int ngb : adj[cur]) {
		if (cm[ngb] == -1) {
			// ngb is not yet colored / visited
			if (dfs(ngb, adj, cm, 1 - c) == false) {
				// subcomponent of ngb is not bipartite
				// therefore component of cur is not biparitite
				return false;
			}
		} else {
			// ngb is already colored / visited
			if (cm[cur] == cm[ngb]) {
				// component of cur is not bipartite
				return false;
			}
		}
	}

	// component of cur is bipartite
	return true;

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

	bool flag = true; // assume graph is bipartite

	vector<int> cm(n, -1);

	// cm[i] stores color assigned to node i

	// cm[i] = 0 means node i is assigned red color
	// cm[i] = 1 means node i is assigned green color
	// cm[i] = -1 means node i is not yet assigned any color

	for (int i = 0; i < n; i++) {

		if (cm[i] == -1) {

			// node i is not yet colored which means its
			// component is not yet processed

			if (dfs(i, adj, cm, 0) == false) {
				// component of node i is not bipartite
				// therefore graph is not bipartite
				flag = false;
				break;
			}

		}

	}

	if (flag == true) {
		cout << "bipartite" << endl;
	} else {
		cout << "not bipartite" << endl;
	}

	return 0;

}