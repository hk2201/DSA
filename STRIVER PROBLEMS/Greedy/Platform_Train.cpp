
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int plat = 1;
        int result = 1;
        int i = 1;
        int j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                plat++;
                i++;
            }
            else
            {
                plat--;
                j++;
            }

            result = max(result, plat);
        }
        return result;
    }
};
