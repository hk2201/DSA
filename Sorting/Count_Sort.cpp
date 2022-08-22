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

// We will recieve maximun number from the array;
int maximun(int *arr, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int size)
{
    int max = maximun(arr, size);  // Receiving maximum number.
    int *count = new int[max + 1]; // creating a new array of size of max element.

    // in this loop we will initiaze all the elements to zero.
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // From given array if there is an element 3 than we will put at index 3 in count array 1.
    for (int i = 0; i < size; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    int i = 0; // For count array
    int j = 0; // for given array

    // Till max is not completed
    while (i <= max)
    {
        if (count[i] > 0)
        // for every element in count is greater than 0 thn in arr[j] we'll add counts index of that element.
        {
            arr[j] = i;
            count[i]--; // Because if in that box number 2 is there thn till zero well decrement.
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {12, 1, 4, 45, 10, 5};
    int size = 6;
    print(arr, size);
    countSort(arr, size);
    print(arr, size);

    return 0;
}