#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> distance(vertices, INT_MAX);
    set<pair<int, int>> st;
    distance[source] = 0;
    st.insert({0, source});
    while (!st.empty())
    {
        auto it = *(st.begin()); // st.begin() will work as iterator and that * will give you the value if star not present than only address will be returned;
        int dist = it.first;
        int node = it.second;
        st.erase(it);

        for (auto at : adj[node])
        {
            int edgeWeight = at.second;
            int adjNode = at.first;
            if (dist + edgeWeight < distance[adjNode])
            {
                distance[adjNode] = dist + edgeWeight;
                st.insert({distance[adjNode], adjNode});
            }
        }
    }

    return distance;
}