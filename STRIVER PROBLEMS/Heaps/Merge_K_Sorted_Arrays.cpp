#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for (int i = 0; i < kArrays.size(); i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            int x = kArrays[i][j];
            pq.push(x);
        }
    }
    int n = pq.size();
    while (n > 0)
    {
        int xm = pq.top();
        pq.pop();
        ans.push_back(xm);
        n--;
    }

    return ans;
}
