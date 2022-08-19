// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    int k;
    cout << "Enter the K" << endl;
    cin >> k;
    int n;
    cout << "Enter the Size" << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the eleemtns" << endl;
        cin >> arr[i];
    }

    Solution hk;
    cout << "The Count is " << hk.getPairsCount(arr, n, k);

    return 0;
}
// } Driver Code Ends