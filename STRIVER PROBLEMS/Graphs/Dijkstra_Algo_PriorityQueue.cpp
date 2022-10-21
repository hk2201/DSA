//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V,INT_MAX);
        distance[S] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dist + edgeWeight < distance[adjNode]){
                    distance[adjNode] = dist + edgeWeight;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }
        return distance;
    }
};
