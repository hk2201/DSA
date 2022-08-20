#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int *arr, int n)
{
    int indexElement;
    for (int i = 0; i < n - 1; i++)
    {
        indexElement = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[indexElement] > arr[j])
            {
                indexElement = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexElement];
        arr[indexElement] = temp;
    }
}

int main()
{

    int arr[] = {20, 41, 5, 12, 10, 30};
    int n = 6;

    print(arr, n);
    SelectionSort(arr, n);
    print(arr, n);

    return 0;
}