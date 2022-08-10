#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void LLtraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *insertFirst(struct Node *head, int data)
{
    struct Node *ptr = new Node;
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct Node *insertatIndex(struct Node *head, int data, int index)
{
    struct Node *naya = new Node;
    naya->data = data;
    struct Node *p = head;
    int i = 0;
    while (i != index)
    {

        p = p->next;
        i++;
    }
    naya->next = p->next;
    p->next = naya;

    return head;
}

struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *last = new Node;
    last->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = last;
    last->next = NULL;

    return head;
}

struct Node *insertNode(struct Node *head, struct Node *prev, int data)
{
    struct Node *hmm = new Node;
    hmm->data = data;

    hmm->next = prev->next;
    prev->next = hmm;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    cout << "Before Insetions" << endl;
    LLtraversal(head);
    cout << endl;

    // Insertion at beginning
    cout << "beginning" << endl;
    head = insertFirst(head, 100);
    LLtraversal(head);
    cout << endl;

    // Insertion at a index
    cout << "At Index" << endl;
    head = insertatIndex(head, 101, 0);
    LLtraversal(head);
    cout << endl;

    // insertion at end
    cout << "At end" << endl;
    head = insertEnd(head, 400);
    LLtraversal(head);
    cout << endl;

    // insertion at particular Node
    cout << "Particular Node" << endl;
    head = insertNode(head, second, 150);
    LLtraversal(head);

    return 0;
}