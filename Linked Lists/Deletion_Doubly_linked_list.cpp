#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void dlTraversal(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

struct Node *beginDeletion(struct Node *head)
{
    struct Node *p1 = head;
    struct Node *ptr = head->next;
    ptr->prev = p1->prev;
    head = p1->next;

    free(p1);

    return head;
}

struct Node* indexDeletion(struct Node* head,int index){
    struct Node* p2 = head;
    struct Node* n1 = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p2 = p2->next;
        n1 = n1->next;
    }
    p2->next = n1->next;
    free(n1);

    return head;
    
}

int main()
{
    struct Node *head = new Node;
    struct Node *second = new Node;
    struct Node *third = new Node;
    struct Node *fourth = new Node;

    head->data = 10;
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = fourth;
    third->prev = second;

    fourth->data = 40;
    fourth->next = NULL;
    fourth->prev = third;

    cout << "Begfore Deletion" << endl;
    dlTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Begin Deletion" << endl;
    head = beginDeletion(head);
    dlTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Deletion at particular Index" << endl;
    head = indexDeletion(head, 1);
    dlTraversal(head);
    cout << endl;
    cout << endl;

    // Rest all deletions are same as prev Linked Lists Deletions.e

    return 0;
}