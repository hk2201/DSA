//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        distance[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int edgeWeight = it.second;
                int adjNode = it.first;
                if (dist + edgeWeight < distance[adjNode])
                {
                    distance[adjNode] = dist + edgeWeight;
                    parent[adjNode] = node;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        if (distance[n] == INT_MAX)
        {
            return {-1};
        }

        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        return path;
    }
};

// Here we have taken parent array where we are from where which node is it comming from so basically parent of that node(shortest Path wala)
// finally node = n which is last...and we will push that in vector and keep on checking where all the nodes are coming from shortest path...till that while condition because the first node is coming from first only so it will break the loop at that time;