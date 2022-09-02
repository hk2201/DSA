#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)

{

    int sum = 0;
    int max[n];
    int i = 0;

    while (i < n)
    {
        sum = sum + arr[i];
        max[i] = sum;
        i++;
    }

    if (sum < 0)
    {
        return 0;
    }

    sort(max, max + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max[n - 1])
        {
            return arr[i];
        }
    }

    return max[n - 1];
}

int main()
{

    int n;

    cout << "Enter the Size od Array" << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Elements" << endl;
        cin >> arr[i];
    }

    int ans = maxSubarraySum(arr, n);
    cout << ans;

    return 0;
}