/*

Implementation of graph search using

  1. depth first search   (dfs)
  2. breadth first search (bfs)

  e.g.

  9 12

  0  1
  0  2
  1  3
  1  4
  2  4
  2  5
  3  6
  4  6
  4  7
  5  7
  6  8
  7  8

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis) {

  vis[cur] = true;
  cout << cur << " ";

  for (int ngb : adj[cur]) {
    if (!vis[ngb]) {
      dfs(ngb, adj, vis);
    }
  }

}

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // comment this out if graph is directed
  }

  int src = 0;

  vector<bool> vis(n, false); // vis[i] tell if node i is visited or not

  dfs(src, adj, vis);

  return 0;

}