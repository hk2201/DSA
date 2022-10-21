/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool diff;
    bool isBalanced(TreeNode *root)
    {
        diff = true;
        check(root);
        return diff;
    }

    int check(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (!diff)
        {
            return false;
        }
        int lh = check(node->left);
        int rh = check(node->right);

        if (abs(lh - rh) > 1)
        {
            diff = false;
        };

        return 1 + max(lh, rh);
    }
};