#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int arr[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    int num = amount;
    for (int i = 8; i >= 0; i--)
    {
        while (num >= arr[i])
        {
            num -= arr[i];
            ans.push_back(arr[i]);
        }
    }
    int count = ans.size();
    return count;
}