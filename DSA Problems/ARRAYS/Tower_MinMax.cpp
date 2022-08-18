// Given an array arr[] denoting heights of N towers and a positive integer K.increase N if N is smaller than K.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Here we'll check if arr[i]>= k if greater than we'll subtract that arr[i] and push in vector.
    int getMinDiff(int arr[], int n, int k)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= k)
            {
                arr[i] -= k;
                v.push_back(arr[i]);
            }
            else
            {
                arr[i] += k;
                v.push_back(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = v[i];
        }
        sort(arr, arr + n);
        int diff = arr[n - 1] - arr[0];
        return diff;
    }
};

//{ Driver Code Starts.
int main()
{
    int k;
    cout << "Enter the K" << endl;
    cin >> k;
    int size;
    cout << "Enter the size" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the elements" << endl;
        cin >> arr[i];
    }

    Solution hk;
    cout << hk.getMinDiff(arr, size, k);

    return 0;
}
// } Driver Code Ends