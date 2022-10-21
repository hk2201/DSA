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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->right == NULL && root->left == NULL)
        {
            return;
        }
        vector<int> ans = preorderTraversal(root);
        TreeNode *node = new TreeNode(ans[1]);
        root->right = node;
        root->left = NULL;
        // TreeNode* node;
        root->left = NULL;
        for (int i = 2; i < ans.size(); i++)
        {
            TreeNode *node2 = new TreeNode(ans[i]);
            node->right = node2;
            node->left = NULL;
            node = node2;
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> pre;
        if (root == NULL)
        {
            return pre;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            pre.push_back(node->val);
            if (node->right != NULL)
            {
                st.push(node->right);
            }
            if (node->left != NULL)
            {
                st.push(node->left);
            }
        }
        return pre;
    }
};

// OPTIMAL

class Solution
{
    node *prev = NULL;

public:
    void flatten(node *root)
    {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};