/*

Given an directed graph do its topological sorting

	e.g.

	8 14

	0 1
	0 2
	0 3
	1 3
	1 4
	3 2
	3 4
	3 5
	3 6
	3 7
	4 6
	5 2
	6 7
	7 5

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); // we are working with directed graph
	}

	vector<int> indeg(n, 0); // indeg[i] stores in-degree of node i

	for (int i = 0; i < n; i++) {
		for (int ngb : adj[i]) {
			indeg[ngb]++;
		}
	}

	// init the queue with all the nodes whose indegree is zero

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) {
			// node i has no dependency
			q.push(i);
		}
	}

	vector<int> topo;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		// cout << cur << " ";
		topo.push_back(cur);

		for (int ngb : adj[cur]) {
			indeg[ngb]--;
			if (indeg[ngb] == 0) {
				q.push(ngb);
			}
		}

	}

	cout << topo.size() << endl;

	for (int x : topo) {
		cout << x << " ";
	}

	cout << endl;


	return 0;

}