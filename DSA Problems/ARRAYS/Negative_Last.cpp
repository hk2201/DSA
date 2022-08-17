//{ Driver Code Starts
// Without changing the order.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                v.push_back(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                v.push_back(arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = v[i];
        }
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
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
    ob.segregateElements(arr, t);
    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}

// } Driver Code Ends