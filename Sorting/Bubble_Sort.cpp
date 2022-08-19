#include <iostream>
using namespace std;

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int *A, int size)
{
    int isSorted = 0;                  // For Adaptive Purpose
    for (int i = 0; i < size - 1; i++) // No of passes
    {
        cout << "No of Passes performed are " << i + 1 << endl;
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++) // For Comparisons
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    // int A[] = {12,1,4,45,10,5};
    int A[] = {1, 2, 3, 4, 5, 6};
    // If array is sorted it should not perform all the passes (making it adaptive)
    int size = 6;

    printArray(A, size);
    BubbleSort(A, size);
    printArray(A, size);

    return 0;
}