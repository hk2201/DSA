bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
{
    vis[node] = 1;
    dfsvis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis, dfsvis))
            {
                return true;
            }
        }
        else if (dfsvis[it])
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<int> vis(n + 1, 0);
    vector<int> dfsvis(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis, dfsvis))
            {
                return true;
            }
        }
    }
    return false;
}