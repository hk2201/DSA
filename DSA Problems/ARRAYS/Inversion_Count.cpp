#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Inversions(int arr[], int size)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
                if (arr[i] > arr[j])
                {
                    count++;
                }
        }

        cout << "The number of inversions are " << count;
    }
};

int main()
{
    int size;

    cout << "Size" << endl;
    cin >> size;
    int count = 0;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the elements" << endl;
        cin >> arr[i];
    }

    Solution hk;
    hk.Inversions(arr, size);

    return 0;
}
