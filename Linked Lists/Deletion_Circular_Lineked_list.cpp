#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void clTraversal(struct Node *head)
{
    struct Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;

    } while (p != head);
}

struct Node *beginningDeletion(struct Node *head)
{
    struct Node *p1 = head;
    struct Node *d = p1->next;

    while (p1->next != head)
    {
        p1 = p1->next;
        d = d->next;
    }
    d->next = head->next;
    p1->next = d->next;
    head = d->next;

    free(d);

    return head;
}

struct Node *atindexDeletion(struct Node *head, int index)
{
    struct Node *p2 = head;
    struct Node *d1 = p2->next;
    for (int i = 0; i < index - 1; i++)
    {
        p2 = p2->next;
        d1 = d1->next;
    }
    p2->next = d1->next;
    free(d1);

    return head;
}

struct Node *endDeletion(struct Node *head)
{
    struct Node *p3 = head;
    struct Node *d2 = p3->next;
    while (d2->next != head)
    {
        p3 = p3->next;
        d2 = d2->next;
    }
    p3->next = d2->next;
    free(d2);

    return head;
}

struct Node *valueDeletion(struct Node *head, int value)
{
    struct Node *p4 = head;
    struct Node *d3 = p4->next;

    for (int i = 0; i < value - 1; i++)
    {
        p4 = p4->next;
        d3 = d3->next;
    }
    p4->next = d3->next;
    free(d3);

    return head;
}

int main()
{
    struct Node *head = new Node;
    struct Node *second = new Node;
    struct Node *third = new Node;
    struct Node *fourth = new Node;
    struct Node *five = new Node;
    struct Node *six = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = five;

    five->data = 50;
    five->next = six;

    six->data = 60;
    six->next = head;

    cout << "Before Deletion" << endl;
    clTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Beginning Deletion" << endl;
    head = beginningDeletion(head);
    clTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Deletion at a particular Index" << endl;
    head = atindexDeletion(head, 1);
    clTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Deletion at End" << endl;
    head = endDeletion(head);
    clTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Deletion of a particular value" << endl;
    head = valueDeletion(head, 40);
    clTraversal(head);
    cout << endl;
    cout << endl;

    return 0;
}