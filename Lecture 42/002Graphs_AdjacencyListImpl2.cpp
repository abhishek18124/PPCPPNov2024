#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<set<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		set<int> ngblist = adj[i];
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