#include <iostream>
using namespace std;

int MaxDiff(int arr[], int n)
{
    int diff = 0;
    int maxdiff = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                diff = arr[j] - arr[i];
            }
            if (diff > maxdiff)
            {
                maxdiff = diff;
            }
        }
    }

    return maxdiff;
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

    cout << MaxDiff(arr, n);

    return 0;
}