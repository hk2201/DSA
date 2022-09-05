#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end, int k)
{
    if (start > end)
    {
        return false;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == k)
    {
        return true;
    }
    if (arr[mid] < k)
    {
        return BinarySearch(arr, mid + 1, end, k);
    }
    else
    {
        return BinarySearch(arr, start, mid - 1, k);
    }
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    int k = 0;
    cout << "Present or Not " << BinarySearch(arr, 0, 5, k);

    return 0;
}