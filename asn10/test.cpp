#include <iostream>
#include <vector>
using namespace std;

int findRoot(vector<int> adj[], int n) {
    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j : adj[i]) {
            degree[j]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 0) {
            return i;
        }
    }
    return -1; // No root found
}

int dfs(int node, vector<int> adj[], int vis[], int depth) {
    vis[node] = 1;
    int sum = depth;
    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            sum += dfs(it, adj, vis, depth + 1);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> adj[n + 2];
    int vis[n + 2];
    for (int i = 0; i < n + 2; i++) {
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p); // Adding edges in both directions for undirected tree
    }
    int root = findRoot(adj, n);
    int ans = dfs(root, adj, vis, 0);
    cout << ans << endl;
    return 0;
}
