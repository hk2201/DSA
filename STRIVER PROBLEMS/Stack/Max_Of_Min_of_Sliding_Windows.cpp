//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int a[], int n)
    {
        stack<int> st;

        int left[n + 1];
        int right[n + 1];

        for (int i = 0; i < n; i++)
        {
            left[i] = -1;
            right[i] = n;
        }

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[st.top()] >= a[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && a[st.top()] >= a[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans[n + 1];
        for (int i = 0; i <= n; i++)
        {
            ans[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;

            ans[len] = max(ans[len], a[i]);
        }

        for (int i = n - 1; i >= 1; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        vector<int> res(n);
        for (int i = 1; i <= n; i++)
        {
            res[i - 1] = ans[i];
        }

        return res;
    }
};

