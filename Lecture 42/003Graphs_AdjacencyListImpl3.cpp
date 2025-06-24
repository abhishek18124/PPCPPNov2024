#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<char, vector<char>> adj;

	for (int i = 0; i < m; i++) {
		char u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment is if you are working with direcrted graph
	}

	for (auto [node, ngblist] : adj) {
		cout << "ngb(" << node << ") : ";
		for (auto ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (pair<char, vector<char>> p : adj) {
		char node = p.first;
		vector<char> ngblist = p.second;
		cout << "ngb(" << node << ") : ";
		for (char ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;

}