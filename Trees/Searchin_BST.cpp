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
    struct Node *ptr = new Node;
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->data) << " ";
        inorder(root->right);
    }
};

bool isBST(struct Node *root)
{
    static struct Node *p = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return false;
        }
        if (p != NULL && root->data <= p->data)
        {
            return false;
        }
        p = root;

        return isBST(root->right);
    }
    else
    {
        return true;
    }
}

struct Node *Searching(struct Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    else if (root->data > val)
    {
        return Searching(root->left, val);
    }
    else
    {
        return Searching(root->right, val);
    }
}

int main()
{

    struct Node *root = create(5);
    struct Node *l1 = create(3);
    struct Node *l2 = create(1);
    struct Node *lr1 = create(4);
    struct Node *r1 = create(6);

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l1->right = lr1;

    inorder(root);
    cout << endl;
    cout << isBST(root);
    cout << endl;
    struct Node *n = Searching(root, 1);
    if (n != NULL)
    {
        cout << "Found " << n->data;
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}