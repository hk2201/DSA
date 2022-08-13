#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void dlTraversal(struct Node* head){
    struct Node* p = head;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    
}



int main(){
    struct Node* head = new Node;
    struct Node* second = new Node;
    struct Node* third = new Node;
    struct Node* fourth = new Node;

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

    dlTraversal(head);




    return 0;
}