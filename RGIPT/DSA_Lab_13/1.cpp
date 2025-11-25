#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, int d, const vector<vector<int>> &adj, vector<int> &visited)
{
    if (u == d)
        return true;
    visited[u] = 1;
    int n = adj.size();
    for (int v = 0; v < n; ++v)
    {
        if (adj[u][v] == 1 && !visited[v])
        {
            if (dfs(v, d, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    int s = 0;
    int d = 4;
    vector<int> visited(adj.size(), 0);

    if (dfs(s, d, adj, visited))
        cout << "Simple path exists\n";
    else
        cout << "No simple path\n";

    return 0;
}
