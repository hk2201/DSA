#include <iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Full Hai";
    }
    else
    {
        q->rear = q->rear + 1;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        cout << "Empty hai" << endl;
        return 0;
    }
    else
    {
        q->front = q->front + 1;
        int val = q->arr[q->front];
        return val;
    }
}

void traversal(struct queue *q)
{
    for (int i = 0; i <= q->rear; i++)
    {
        cout << q->arr[i] << " ";
    }
}

int main()
{
    // Either we can create dynamically like we did in stack and all that(pointer new Node etc) or else this way also same.

    struct queue q;
    q.front = q.rear = -1;
    q.size = 4;
    q.arr = new int[q.size];

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    // traversal(&q);

    return 0;
}