// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// void traversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         cout << ptr->data << " ";
//         ptr = ptr->next;
//     }
// }

// int isEmpty(struct Node *top)
// {
//     if (top == NULL)
//     {
//         return 1;
//     }
//     return 0;
// }

// int isFull(struct Node *top)
// {
//     struct Node *ptr = new Node;
//     if (ptr == NULL)
//     {
//         return 1;
//     }
//     return 0;
// }

// struct Node *push(struct Node *top, int data)
// {
//     if (isFull(top))
//     {
//         cout << "Stack is Full" << endl;
//     }
//     else
//     {
//         struct Node *p = new Node;
//         p->next = top;
//         p->data = data;
//         top = p;

//         return top;
//     }
// }

// int pop(struct Node *top)
// {
//     if (isEmpty(top))
//     {
//         cout << "stack is Empty" << endl;
//     }
//     else
//     {
//         struct Node *p1 = top;
//         top = top->next;
//         int el = p1->data;
//         free(p1);

//         return el;
//     }
// }

// int main()
// {
//     struct Node *top = NULL;

//     top = push(top,10);
//     top = push(top,20);
//     traversal(top);
//     cout<<endl;
//     cout<<"The popped element is"<<endl;
//     cout<<pop(top)<<endl;
//     cout<<pop(top)<<endl;

//     // traversal(top);

//     return 0;
// }

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = new Node;
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        cout << ("Stack Overflow");
    }
    else
    {
        struct Node *n = new Node;
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        cout << ("Stack Underflow");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr->next!= NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int peek(struct Node *top, int index)
{
    struct Node *p1 = top;
    for (int i = 0; (i < index - 1 && p1 != NULL); i++)
    {
        p1 = p1->next;
    }
    if (p1 != NULL)
    {
        return p1->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    linkedListTraversal(top);

    int element = pop(&top);
    cout << "Popped element is " << element << endl;
    linkedListTraversal(top);
    int ts = peek(top, 2);
    cout << "The peeked element is " << endl;
    cout << ts << endl;
    int tp = stackTop(top);
    cout << "The Top element is " << endl;
    cout << tp << endl;
    int dn = stackBottom(top);
    cout << "The Bottom element is " << endl;
    cout << dn << endl;

    return 0;
}
