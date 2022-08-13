#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

void push(struct stack *p, int val)
{
    if (p->top == p->size - 1)
    {
        cout << "stack Overflow" << endl;
    }
    else
    {
        p->top = p->top + 1;
        p->arr[p->top] = val;
    }
}

int stackTop(struct stack *ptr)
{
    int val = ptr->arr[ptr->top];

    return val;
}

int stackBottom(struct stack *ptr)
{
    int val1 = ptr->arr[0];

    return val1;
}

int main()
{
    struct stack *s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    cout << "Top of the stack is " << stackTop(s) << endl;
    cout << "Bottom of the stack is " << stackBottom(s) << endl;

    return 0;
}