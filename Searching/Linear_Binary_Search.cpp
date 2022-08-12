#include <iostream>
using namespace std;

// This is a return function and not a void function.

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; // will returun the index of the element
        }
    }
    return -1; // will return if elemnt not found
}

int binarySearch(int arr[],int size,int element){
    int low,mid,high;

    low = 0;
    high = size-1;

    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]==element){
            return mid; 
        }
        if(arr[mid]<element){
            low = mid + 1;
            return low;
        }
        else{
            high = mid - 1;
            return high;
        }

    }
    return -1;

}

int main()
{
    // Unsorted array for linear search

    // int array[] = {1, 2, 3, 4, 5, 6, 7, 86, 54, 79, 61, 47};
    // int size = sizeof(array) / sizeof(int); // This is how you calculate size
    // int element = 3;
    // int search = linearSearch(array, size, element);
    // cout << "The element " << element << " was found at " << search;

    // Sorted array for binary search

    int array[] = {1,2,3,4,6,7,8,9,10};
    int size = sizeof(array)/sizeof(int);
    int element = 2;
    int binary = binarySearch(array,size,element);
    cout<<"The element "<<element<<" was found at "<<binary;


    return 0;
}