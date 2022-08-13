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

struct Node *beginInsertion(struct Node *head, int data)
{
    struct Node *p1 = head;
    struct Node *n1 = new Node;
    n1->prev = p1->prev;
    n1->data = data;
    n1->next = p1;
    p1->prev = n1;
    head = p1->prev;

    return head;
}

struct Node *indexInsertion(struct Node *head, int index, int data)
{
    struct Node *p2 = head;
    struct Node *n2 = new Node;
    n2->data = data;
    for (int i = 0; i < index - 1; i++)
    {
        p2 = p2->next;
    }
    n2->next = p2->next;
    p2->next = n2;
    n2->prev = p2;

    return head;
}

struct Node* endInsertion(struct Node* head,int data){
    struct Node* p3 = head;
    struct Node* n3 = new Node;
    n3->data = data;
    while(p3->next!=NULL){
        p3 = p3->next;
    }
    n3->next = p3->next;
    p3->next = n3;
    n3->prev = p3;
    
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

    cout << "Before Insertion" << endl;
    dlTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Beginning Insertion" << endl;
    head = beginInsertion(head, 100);
    dlTraversal(head);
    cout << endl;
    cout << endl;

    cout << "Insertion at Given Index" << endl;
    head = indexInsertion(head, 1, 200);
    dlTraversal(head);
    cout << endl;
    cout << endl;

    cout<<"End Insertion"<<endl;
    head = endInsertion(head,300);
    dlTraversal(head);
    cout<<endl;
    cout<<endl;

    // Insertion at given pointer location is same as others only add previous linkage.

    

    return 0;
}