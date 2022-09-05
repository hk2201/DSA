#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sort_array_0_1_2(int A[], int n)
{
    int low = 0, high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        if (A[mid] == 0)
        {
            swap(&A[low], &A[mid]);
            low = low + 1;
            mid = mid + 1;
        }
        else if (A[mid] == 1)
        {
            mid = mid + 1;
        }
        else
        {
            swap(&A[high], &A[mid]);
            high = high - 1;
        }
    }
}
int main()
{
    int i, A[100], n;
    cout << " Enter number of elements present in the array: " << endl;
    cin >> n;
    cout << " Enter array:  " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << " Array after sorting : \n " << endl;
    sort_array_0_1_2(A, n);
    for (i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}