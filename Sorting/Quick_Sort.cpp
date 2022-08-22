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

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (pivot >= arr[i]) // jab tak arr[i] pivot se badha nhi milta tab tak.
        {
            i++;
        }
        while (arr[j] >= pivot) // jab tak arr[j] pivot se chota nhi milta tab tak.
        {
            j--;
        }
        if (j > i) //  interchanging jab tak j...i ke aage hai.
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (j > i); // tab j< i bahaar ajayega loop se.
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // pivot position yaha pr ajeyga.
}

void quickSort(int *arr, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        // low toh isi funtion(quickSort) ka hai but partitionindex yaha pr return j rahega.

        quickSort(arr, partitionIndex + 1, high);
        // high usi function(quickSort) ka hai.
    }
}

int main()
{

    int arr[] = {20, 1, 5, 15, 12, 17};
    int size = 6;

    print(arr, size);
    quickSort(arr, 0, size - 1);
    print(arr, size);

    return 0;
}