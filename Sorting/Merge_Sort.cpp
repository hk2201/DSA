#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeAlgo(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int *b = new int[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

// Recursive Merge Sort
void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeAlgo(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {20, 41, 5, 12, 10, 30};
    int size = 6;
    print(arr, size);
    mergeSort(arr, 0, size - 1);
    print(arr, size);

    return 0;
}