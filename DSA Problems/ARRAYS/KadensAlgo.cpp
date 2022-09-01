// Find the max sum of the subarray in that array.

//{ Driver Code Starts
// Without changing the order.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long maxSum(int arr[], int n)
    {
        int max = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > max)
            {
                max = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }
        return max;
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes herezz
    int t;
    cout << "Enter the size" << endl;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        cout << "Enter the elemets" << endl;
        cin >> arr[i];
    }

    Solution ob;
    cout << ob.maxSum(arr, t);
}

// } Driver Code Ends