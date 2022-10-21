// CAN ALSO USE STACK AS YOU DO IN NORMAL DFS TRAVERSAL;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            //             dfs(it,node,adj,vis);
            if (dfs(it, node, adj, vis))
            {
                return true;
            }
        }
        else if (parent != it)
        {
            return true;
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
            if (dfs(i, -1, adj, vis))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

