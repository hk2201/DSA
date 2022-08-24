#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postOrder(struct Node *p)
{
    if (p!=NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<" ";
    } 
    
}

void inOrder(struct Node* p){
    if (p!=NULL)
    {
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
    
}

int main()
{
    /*
    // Constructing the root node
    struct Node *p;
    p = new Node;
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct Node *p1;
    p1 = new Node;
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct Node *p2;
    p2 = new Node;
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */

    // Constructing the root node
    struct Node *p = createNode(10);

    // Constructing the second node
    struct Node *p1 = createNode(20);

    // Constructing the third node
    struct Node *p2 = createNode(30);

    p->left = p1;
    p->right = p2;
    // preorder(p);
    // postOrder(p);
    inOrder(p);


    return 0;
}