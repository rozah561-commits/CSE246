
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node) {
    visited[node] = true;

    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(adj, visited, neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    // input edges (undirected)
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    int components = 0;

    // check all nodes
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(adj, visited, i); // explore full component
            components++;         // one component found
        }
    }

    cout << components << endl;

    return 0;
}
