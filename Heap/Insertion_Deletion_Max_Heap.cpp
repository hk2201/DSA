#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteheap()
    {
        if (size == 0)
        {
            cout << "Kuch bhi nhi hai" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int lifenode = 2 * i;
            int rightnode = 2 * i + 1;
            if (lifenode < size && arr[i] < arr[lifenode])
            {
                swap(arr[i], arr[lifenode]);
                i = lifenode;
            }
            else if (rightnode < size && arr[i] < arr[rightnode])
            {
                swap(arr[i], arr[rightnode]);
                i = rightnode;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftnode = 2 * i;
    int rightnode = 2 * i + 1;

    if (leftnode <= n && arr[largest] < arr[leftnode])
    {
        largest = leftnode;
    }
    if (rightnode <= n && arr[largest] < arr[rightnode])
    {
        largest = rightnode;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.deleteheap();
    h.print();

    int arr[6] = {-1, 50, 52, 53, 54, 55};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}