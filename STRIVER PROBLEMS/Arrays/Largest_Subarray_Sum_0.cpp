#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{

    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = -1;
    int global = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (mp.find(sum) != mp.end())
        {
            global = max(global, i - mp[sum]);
            continue;
        }
        else
        {
            mp[sum] = i;
        }
    }
    return global;
}

int main(){

    vector<int> arr = {9, -3, 3, -1, 6, -5};

    int ans = LongestSubsetWithZeroSum(arr);

    cout<<"Longest Subarray with sum zero is "<<ans;



    return 0;
}