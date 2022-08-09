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
        cout << "The elementis " << ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap 
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    // Linking of the Nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    LLtraversal(head);
    return 0;
}