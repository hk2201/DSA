#include <bits/stdc++.h>
void sortStack(stack<int> &stack)
{
    vector<int> ans;
    while (!stack.empty())
    {
        ans.push_back(stack.top());
        stack.pop();
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        stack.push(ans[i]);
    }
}