#include <iostream>
using namespace std;

//  Explanation in NoteBook

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *
create(int data)
{
    struct Node *p = new Node;
    p->data = data;
    p->right = NULL;
    p->left = NULL;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int succ(struct Node *root)
{
    int min = root->data;
    while (root->left != NULL)
    {
        min = root->data;
        root = root->left;
    }
    return min;
}

struct Node *Deletion(struct Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == val)
    {
        free(root);
        return NULL;
    }

    // Searching Val
    if (val < root->data)
    {
        root->left = Deletion(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = Deletion(root->right, val);
    }
    else
    {
        root->data = succ(root->right);
        root->right = Deletion(root->right, root->data);
    }

    return root;
}

int main()
{
    struct Node *root = create(7);
    struct Node *l = create(3);
    struct Node *ll = create(1);
    struct Node *lr = create(5);
    struct Node *lrl = create(4);
    struct Node *lrr = create(6);
    struct Node *r = create(8);

    root->left = l;
    root->right = r;

    l->left = ll;
    l->right = lr;

    lr->left = lrl;
    lr->right = lrr;

    inorder(root);
    Deletion(root, 7);
    cout << endl;
    inorder(root);

    return 0;
}