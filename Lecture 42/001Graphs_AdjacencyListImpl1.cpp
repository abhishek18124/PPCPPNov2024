#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	// assume nodes are labelled from 0 to n-1

	// here n represents no. of nodes in the graph
	// and  m represents no. of edges in the graph

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this if edge is directed
	}

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;

}