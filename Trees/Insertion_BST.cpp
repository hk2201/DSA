#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int data)
{
    struct Node *p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void insert(struct Node *root, int val)
{
    // We'll Create a prev and initialize to NULL So after that we will use while Loop and run it till NULL.
    struct Node *prev = NULL;
    while (root != NULL)
    {
        // In starting we will set prev as root(we will have val of root) so it root is node 3 prev will be at 5 according our Trees we have used.
        prev = root;
        if (root->data == val)
        {
            cout << "Cannot Insert Sorry" << endl;
            return;
        }
        else if (val < root->data)
        {
            root = root->left;
        }
        
        else
        {
            root = root->right;
        }
    }
    struct Node *neww = create(val); // New Node that we will be linking

    // as Prev is before Node so here again we will check for the Below Condition.(after Loop ROOT will be NULL)
    if (val > prev->data)
    {
        prev->right = neww;
    }
    else
    {
        prev->left = neww;
    }
}

int main()
{

    struct Node *root = create(5);
    struct Node *l = create(3);
    struct Node *ll = create(1);
    struct Node *lr = create(4);
    struct Node *r = create(6);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;

    inOrder(root);

    insert(root, 0);
    cout << endl;
    inOrder(root);

    return 0;
}