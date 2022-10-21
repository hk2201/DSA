#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    int child = 0;
    if (root->left != NULL)
    {
        child += root->left->data;
    }
    if (root->right != NULL)
    {
        child += root->right->data;
    }

    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left != NULL)
        {
            root->left->data = root->data;
        }
        else if (root->right != NULL)
        {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left != NULL)
    {
        tot += root->left->data;
    }
    if (root->right != NULL)
    {
        tot += root->right->data;
    }
    if (root->right != NULL || root->left != NULL)
    {
        root->data = tot;
    }
}