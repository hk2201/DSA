//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
    {
        storeDfs.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, storeDfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> storeDfs;
        vector<int> vis(V + 1, 0);
        for (int i = 1; i < V; i++)
        {
            if (!vis[i])
                dfs(0, vis, adj, storeDfs);
        }
        return storeDfs;
    }
};

// Alternate Solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        stack<int> st;
        vector<int> vis(V + 1, 0);
        st.push(0);
        vis[0] = 1;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            ans.push_back(node);
            for (int i = adj[node].size() - 1; i >= 0; i--)
            {
                int p = adj[node][i];
                if (!vis[p])
                {
                    st.push(p);
                    vis[p] = 1;
                }
            }
        }
        return ans;
    }
};
