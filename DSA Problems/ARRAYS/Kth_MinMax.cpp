#include <iostream>
using namespace std;

class arrays
{
    int size;
    int *arr;

public:
    arrays(int s)
    {
        size = s;
        int *arr = new int[s];
    }

    void get()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter elements" << endl;
            cin >> arr[i];
        }
    }

    void display(int index)
    {
        index = size - index;
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

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "The Kth max element is " << arr[index];
    }
};

int main()
{
    int sz;
    cin >> sz;
    arrays hk(sz);
    hk.get();
    hk.display(1);
    

    return 0;
}