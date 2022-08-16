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

struct Node *deletionFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
};

struct Node *deletioninBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q1 = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q1 = q1->next;
        i++;
    }
    p->next = q1->next;
    free(q1);

    return head;
}

struct Node *deletionatEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
};

struct Node *deletionforValue(struct Node *head, int value)
{
    struct Node *p1 = head;
    struct Node *a = head->next;
    while (a->data != value && a->next != NULL)
    {
        p1 = p1->next;
        a = a->next;
    }

    if (a->data == value)
    {
        p1->next = a->next;
        free(a);
    }

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *five;
    struct Node *six;

    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    five = new Node;
    six = new Node;

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
    six->next = NULL;

    cout << "Before Deletion" << endl;
    LLtraversal(head);
    cout << endl;

    cout << "Deletion at Beginning" << endl;
    head = deletionFirst(head);
    LLtraversal(head);
    cout << endl;

    cout << "Deletion in Between" << endl;
    head = deletioninBetween(head, 2);
    LLtraversal(head);
    cout << endl;

    cout << "Deletion at end" << endl;
    head = deletionatEnd(head);
    LLtraversal(head);
    cout << endl;

    cout << "Deletion for a particular value" << endl;
    head = deletionforValue(head, 30);
    LLtraversal(head);

    return 0;
}