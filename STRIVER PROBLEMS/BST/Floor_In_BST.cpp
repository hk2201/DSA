
int floorInBST(TreeNode<int> *root, int X)
{
    int num = -1;
    while (root)
    {
        if (root->val == X)
        {
            num = root->val;
            return num;
        }

        if (X < root->val)
        {
            root = root->left;
        }
        else
        {
            num = root->val;
            root = root->right;
        }
    }
    return num;
}