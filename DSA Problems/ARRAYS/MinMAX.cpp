#include <iostream>
using namespace std;

class arrays
{
    int size;
    int *arr;

public:
    arrays(int sz)
    {
        size = sz;
        int *arr = new int[sz];
    }

    void getele();

    void Max();
};

void arrays::getele()
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void arrays::Max()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[i] >= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    cout<<"The Max Element is "<<arr[size-1]<<endl;
    cout<<"The Min Element is "<<arr[0];
}


int main()
{
    int tl;
    cin >> tl;
    arrays hk(tl);
    hk.getele();
    hk.Max();
    return 0;
}