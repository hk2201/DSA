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
        q->rear = q->rear - 1;
        int val = q->arr[q->rear];