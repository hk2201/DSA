#include <iostream>
using namespace std;

// Here Simply What we'll do is check is next number is greater than the prev and later subtract it and store in var. and accordingly perform.

int Best(int *arr, int size)
{
    int profit = 0;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                profit = arr[j] - arr[i];
            }
            if (profit > max)
            {
                max = profit;
            }
            else
            {
                profit = 0;
            }
        }
    }
    return max;
}

int main()
{
    int arr[] = {7,6,4,3,1};
    int size = 5;
    cout << Best(arr, size);

    return 0;
}