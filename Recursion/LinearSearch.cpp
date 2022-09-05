#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size,int k)
{
    // Base case dhundhte dhundhte nhi mila tab size 0 hogaya toh...
    if (size == 0 )
    {
        return false;
    }
    if (arr[0]==k)
    {
        return true;
    }
    else{
        bool remainingpart = LinearSearch(arr+1,size-1,k);
        return remainingpart;
    }
    
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int k = 1;

    bool ans = LinearSearch(arr, size,k);

    if (ans)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    return 0;
}