class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
            {
                continue;
            }
            else
            {
                vis[node] = 1;
                sum += wt;
                // IF MST IS ALSO ASKED JUST MAKE SURE YOU CREATE ONE MORE VECTOR TO STORE IT AND ALSO IN PQ ADD PARENT ASLO;
            }

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int adjWeight = it[1];
                if (!vis[adjNode])
                {
                    pq.push({adjWeight, adjNode});
                }
            }
        }
        return sum;
    }
};