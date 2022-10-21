bool isLeaf(TreeNode<int> *root)
{
    if (root->left == NULL and root->right == NULL)
        return true;
    return false;
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root->left;
    while (curr != NULL)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left != NULL)
        addLeaves(root->left, ans);
    if (root->right != NULL)
        addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root->right;
    vector<int> temp;
    while (curr != NULL)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right != NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    for (auto x : temp)
    {
        ans.push_back(x);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }

    // 3 steps
    // 1.) Left boundary excluding leaf nodes
    addLeftBoundary(root, ans);

    // 2.)Leaf nodes
    addLeaves(root, ans);

    // 3.)Right boundary in reverse order excluding leaf nodes
    addRightBoundary(root, ans);

    return ans;
}