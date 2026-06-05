#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node) {
    visited[node] = true;
    cout << node << " ";
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(adj, visited, neighbor);
        }
    }
}
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<bool> visited(n, false);
    dfs(adj, visited, s);
    return 0;
}
