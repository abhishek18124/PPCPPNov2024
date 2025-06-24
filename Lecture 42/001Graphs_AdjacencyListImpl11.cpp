#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	// assume nodes are labelled from 1 to n

	// here n represents no. of nodes in the graph
	// and  m represents no. of edges in the graph

	vector<vector<int>> adj(n + 1); // n+1 since nodes are labelled from 1 to n
	// index 0 is not used when nodes follow 1-based numbering

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// u--; v--; // uncomment this if adj is of size n and you want to take input as 0-based
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this if edge is directed
	}


	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		vector<int> ngblist = adj[i];
		for (int ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;

}