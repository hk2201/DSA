/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool getpath(TreeNode *root, vector<int> &ans, int B)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->val);
    if (root->val == B)
    {
        return true;
    }

    if (getpath(root->left, ans, B) || getpath(root->right, ans, B))
    {
        return true;
    }

    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> ans;
    getpath(A, ans, B);
    return ans;
}