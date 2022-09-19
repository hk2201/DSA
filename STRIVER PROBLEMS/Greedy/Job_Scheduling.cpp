//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
        {
            slot[i] = -1;
        }

        int countjobs = 0;
        int maxprofit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    countjobs++;
                    maxprofit += arr[i].profit;
                    break;
                }
            }
        }

        vector<int> ans;
        ans.push_back(countjobs);
        ans.push_back(maxprofit);

        return ans;
    }
};