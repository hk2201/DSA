#include <iostream>
using namespace std;

struct array
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct array *arr, int val)
{
    // we'll be using circular inc. here so that after reaching the end the % we get 0 that is start.
    if ((arr->rear + 1) % arr->size == arr->front)
    {
        cout << "Overflow";
    }
    else
    {
        // Same operations as linear queue just for inc. purpose we'll be using circular inc.
        arr->rear = (arr->rear + 1) % arr->size;
        arr->arr[arr->rear] = val;
    }
}

int dequeue(struct array *arr)
{
    if (arr->front == arr->rear)
    {
        cout << "Empty hai re" << endl;
        return 0;
    }
    else
    {
        arr->front = (arr->front + 1) % arr->size;
        int val = arr->arr[arr->front];

        return val;
    }
}

int main()
{

    struct array *arr = new array;
    arr->size = 10;
    arr->front = arr->rear = 0;  // if -1 the circular inc will never find -1.
    arr->arr = new int[arr->size];

    enqueue(arr, 10);
    enqueue(arr, 20);
    cout << dequeue(arr) << endl;
    cout << dequeue(arr) << endl;
    cout << dequeue(arr) << endl;
    enqueue(arr, 100);
    cout << dequeue(arr) << endl;

    return 0;
}
