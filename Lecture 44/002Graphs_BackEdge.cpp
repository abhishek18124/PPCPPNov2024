/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& stk) {

	vis[cur] = true;
	stk[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			if (dfs(ngb, adj, vis, stk)) {
				// you've found a backedge in the subcomponent of ngb
				// therefore you've found a backedge in the component
				// of cur
				return true;
			}
		} else {
			// ngb is already visited so maybe the edge from cur to ngb is a backedge
			// to check if that is the case, you've to see if there is a directed from
			// ngb to cur and to do this all you've to do is check if at this point of
			// time ngb is present on the fn call stack
			if (stk[ngb] == true) {
				// ngb is on the function call stack therefore there is a directed
				// path from ngb to cur hence cur to ngb is a backedge
				return true;
			}
		}
	}

	stk[cur] = false;
	return false; // no backedge found in the component of cur

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); // graph is directed
	}

	bool flag = false; // assume no directed cycle is present in the graph
	vector<bool> vis(n, false); // vis[i] indicates if node i is visited or not
	vector<bool> stk(n, false); // stk[i] indicates if node i is present on fn call stack or not

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// check if there is a directed cycle in the component of node i
			if (dfs(i, adj, vis, stk)) {
				// you've found a backedge i.e. a directed cycle in the
				// component of node i therefore you've found a cycle in
				// the given directed graph
				flag = true;
				break;
			}
		}
	}

	if (flag == false) {
		cout << "no directed cycles found" << endl;
	} else {
		cout << "you've found a directed cycle" << endl;
	}


	return 0;

}