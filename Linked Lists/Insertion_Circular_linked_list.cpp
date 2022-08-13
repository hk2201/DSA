#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void clTraversal(struct Node* head){
    struct Node* p = head;
    do{
        cout<<p->data<<" ";
        p=p->next;

    }
    while(p!=head);
}

struct Node* beginnignInsertion(struct Node* head,int data){
    struct Node* p1 = head;
    struct Node* n1 = new Node;
    n1->data = data;
    while(p1->next!=head){
        p1 = p1->next;
    }
    p1->next = n1;
    n1->next = head;
    head = n1;

    return head;


}

struct Node* inbetweenInsertion(struct Node* head,int index,int data){
    struct Node* p2 = head;
    struct Node* n2 = new Node;
    n2->data = data;
    for (int i = 0; i < index; i++)
    {
        p2 = p2->next;
    }
    n2->next = p2->next;
    p2->next = n2;

    return head;

    
}

struct Node* endInsertion(struct Node* head,int data){
    struct Node* p3 = head;
    struct Node* n3 = new Node;
    n3->data = data;
    while(p3->next!=head){
        p3 = p3->next;
    }
    n3->next = p3->next;
    p3->next = n3;

    return head;
    
    
}

struct Node* givennodeInsertion(struct Node* head,struct Node* given,int data){
    struct Node* p4 = given;
    struct Node* n4 = new Node;
    n4->data = data;
    n4->next = given->next;
    given->next = n4;

    return head;

}



int main(){

    struct Node* head = new Node;
    struct Node* second = new Node;
    struct Node* third = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = head;

    cout<<"Before Insertion"<<endl;
    clTraversal(head);
    cout<<endl;
    cout<<endl;

    cout<<"Insertion at Beginning"<<endl;
    head = beginnignInsertion(head,40);
    clTraversal(head);
    cout<<endl;
    cout<<endl;

    cout<<"Insertion at particular Indexx"<<endl;
    head = inbetweenInsertion(head,0,200);
    clTraversal(head);
    cout<<endl;
    cout<<endl;

    cout<<"Insertion at the End"<<endl;
    head = endInsertion(head,300);
    clTraversal(head);
    cout<<endl;
    cout<<endl;

    cout<<"Insertion at Given Node"<<endl;
    head = givennodeInsertion(head,third,400);
    clTraversal(head);


    
    return 0;
}