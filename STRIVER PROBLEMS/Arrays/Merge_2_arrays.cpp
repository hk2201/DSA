#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
            sort(arr2, arr2 + m);
        }
    }
    sort(arr1, arr1 + n);
    

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr1[] = {3, 1, 5, 7};
    int arr2[] = {2, 0, 6, 8, 9};
    int n = 4;
    int m = 5;

    merge(arr1, arr2, n, m);

    return 0;
}