#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int d, vector<vector<int>> &adj, vector<int> &vis) {
    if (u == d) return true;
    vis[u] = 1;
    int n = adj.size();
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !vis[v]) {
            if (dfs(v, d, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][4] = 1;
    adj[0][2] = 1;

    int s = 0, d = 4;
    vector<int> vis(n, 0);
    bool hasPath = dfs(s, d, adj, vis);

    cout << "Graph has simple path from " << s << " to " << d << ": ";
    if (hasPath) cout << "YES";
    else cout << "NO";
    cout << endl;

    return 0;
}
