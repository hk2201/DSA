#include <iostream>
using namespace std;

// Declaring global variables because if we right this in main it is just copy and not actually work.
struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

// As we declared Global var so no neet to add attri. struct and all that
void enqueue(int val)
{
    struct Node *n = new Node;
    n->data = val;
    if (n == NULL)
    {
        cout << "Full Hai" << endl;
    }
    else
    {
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;   // staring me f null hai isiliey or else print nhi karega.
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int deqeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        cout << "Empty hai re Baba" << endl;
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    linkedListTraversal(f);
    cout << deqeue() << endl;
    linkedListTraversal(f);

    return 0;
}