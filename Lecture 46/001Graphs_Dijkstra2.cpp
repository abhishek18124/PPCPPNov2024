/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int src = 0; // assume node 0 to be the src vertex

	vector<int> dis(n, INF);
	dis[src] = 0;

	vector<bool> ex(n, false); // init no nodes is explored

	set<pair<int, int>> minHeap; // to track unexplored nodes // pair<distance, node>
	minHeap.insert({dis[src], src});

	// time : O(ElogV)
	// space: O(V) due to ex[], dis[], minHeap

	while (!minHeap.empty()) {

		auto[dis_cur, cur] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		for (auto [ngb, edgeWgt] : adj[cur]) {
			if (!ex[ngb] and dis[ngb] > dis_cur + edgeWgt) {

				// edge b/w cur and ngb is tensed so relax it

				// auto it = minHeap.find({dis[ngb], ngb});
				// minHeap.erase(it); // // this may cause a crash in case {dis[ngb], ngb} isn't present in the minHeap

				minHeap.erase({dis[ngb], ngb});
				dis[ngb] = dis_cur + edgeWgt;
				minHeap.insert({dis[ngb], ngb});

			}
		}

		ex[cur] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis[" << i << "] = " << dis[i] << endl;
	}

	return 0;
}