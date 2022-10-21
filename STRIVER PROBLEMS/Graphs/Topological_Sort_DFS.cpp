class Solution
{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                findTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int N, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                findTopoSort(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

// ANOTHER SOLUTION

#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> ind(v, 0);
    vector<int> adj[v + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int vv = edges[i][1];
        adj[u].push_back(vv);
    }
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            ind[it]++;
        }
    }

    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (ind[i] == 0)
        {
            st.push(i);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            ind[it]--;
            if (ind[it] == 0)
            {
                st.push(it);
            }
        }
    }
    return ans;
}