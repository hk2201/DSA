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
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int arr[] = {20, 41, 5, 12, 10, 30};
    int n = 6;

    print(arr, n);
    SelectionSort(arr, n);
    print(arr, n);

    return 0;
}