class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        partialInorder(root);
    }

    void partialInorder(TreeNode *root)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *top = s.top();
        s.pop();
        if (top->right != NULL)
        {
            partialInorder(top->right);
        }

        return top->val;
    }

    bool hasNext()
    {
        if (s.empty())
        {
            return false;
        }
        return true;
    }
};