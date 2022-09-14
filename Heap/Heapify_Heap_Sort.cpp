#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{

    int size = n;
    while (size > 0)
    {
        swap(arr[size - 1], arr[0]);
        size--;

        heapify(arr, size, 0);
    }
}

int main()
{

    int arr[5] = {50, 52, 53, 54, 55};
    int n = 5;

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}