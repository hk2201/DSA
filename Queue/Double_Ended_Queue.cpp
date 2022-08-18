#include <iostream>
using namespace std;

// Not proper.

struct queue
{
    int size;
    int *arr;
    int f;
    int r;
};
int isempty(struct queue *q)
{
    if (q->r == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
void displaylist(struct queue *ptr)
{
    cout << "Elements of queue are" << endl;
    int i = 0;
    while (i <= ptr->r)
    {
        cout << ptr->arr[i];
        i++;
    }
}
void enqueueR(struct queue *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = value;
    }
}
void enqueuef(struct queue *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (ptr->f == -1)
        {
            ptr->f++;
            ptr->arr[ptr->f] = value;
        }

        // ptr->f;
    }
}
int dequeueR(struct queue *ptr)
{
    int x = -1;
    if (isempty(ptr))
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {

        x = ptr->arr[ptr->r];
        ptr->r--;
    }
    return x;
}
int dequeuef(struct queue *ptr)
{
    int x = -1;
    if (isempty(ptr))
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        if (ptr->f == -1)
        {
            ptr->f++;
        }
        x = ptr->arr[ptr->f];
        // ptr->f--;
    }
    return x;
}

int main()
{
    struct queue *de = new queue;
    de->size = 7;
    de->arr = new int[de->size];
    de->f = -1;
    de->r = -1;
    enqueueR(de, 2);
    enqueueR(de, 4);
    enqueueR(de, 6);
    enqueueR(de, 8);
    enqueueR(de, 3);
    enqueueR(de, 5);
    enqueueR(de, 7);
    displaylist(de);
    enqueueR(de, 9);
    cout << endl;
    cout << dequeueR(de) << endl;
    cout << dequeueR(de) << endl;
    cout << dequeueR(de) << endl;
    cout << dequeueR(de) << endl;
    cout << dequeueR(de) << endl;
    // cout << dequeueR(de) << endl;
    // cout << dequeueR(de) << endl;

    enqueuef(de, 3);
    enqueuef(de, 1);
    displaylist(de);
    return 0;
}
