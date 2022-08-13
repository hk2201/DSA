#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void cirtraversal(struct Node* head){
    struct Node* p = head;
    // while(p->next!=head){
    //     cout<<p->data<<" ";

    //     p = p->next;
    // }
    // cout<<p->data;  
    do{
        cout<<p->data<<" ";

        p = p->next;
    }while(p!=head);       
    
    // Yahs pr p not equal to head so abhi filhal p head pr ho hai so jab tak p waps se head pr nhi aata tab tak print karta rahega(humne do while loop me pehle p to next krdiya so isiliye woh dhundhta rahega head)
}



int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;

    head  = new Node;
    second  = new Node;
    third = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = head;

    cirtraversal(head);

    return 0;
}