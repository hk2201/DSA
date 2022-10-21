#include <queue>

bool bfs(int node, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    vis[node] = 1;
    while (!q.empty())
    {
        int num = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[num])
        {
            if (!vis[it])
            {
                q.push({it, num});
                vis[it] = 1;
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<int> vis(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, adj, vis))
            {
                return "Yes";
            }
        }
    }
    return "No";
}