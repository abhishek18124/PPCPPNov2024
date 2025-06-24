#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	map<char, vector<pair<char, int>>> adj;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		char u, v;
		cin >> u >> v;

		int w;
		cin >> w;

		// add an edge b/w u and v of wgt w

		adj[u].push_back({v, w}); // adj[u].push_back(make_pair(v, w));
		adj[v].push_back({u, w}); // comment this if graph is directed

	}

	for (auto [node, ngblist] : adj) {
		cout << "ngb(" << node << ") : ";
		for (auto [ngb, edgeWgt] : ngblist) {
			cout << "(" << ngb << ", " << edgeWgt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	for (pair<char, vector<pair<char, int>>> p : adj) {
		char node = p.first;
		vector<pair<char, int>> ngblist = p.second;
		cout << "ngb(" << node << ") : ";
		for (pair<char, int> pp : ngblist) {
			char ngb = pp.first;
			int edgeWgt = pp.second;
			cout << "(" << ngb << ", " << edgeWgt << ") ";
		}
		cout << endl;
	}

	return 0;

}