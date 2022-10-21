//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ind(V,0);
        
        for(int i = 0 ; i <V;i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0 ; i <V;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0){
                    q.push(it);
                } 
            }
        }
        
        if(cnt == V){
            return false;
        }
        return true;
    }
};

