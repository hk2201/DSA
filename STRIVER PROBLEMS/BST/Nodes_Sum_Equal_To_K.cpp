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
    vector<int> inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ans;
        inorderTraversal(root, ans);
        int j = ans.size() - 1;
        int i = 0;
        int sum = 0;
        while (i < j)
        {
            sum = ans[i] + ans[j];
            if (sum > k)
            {
                j--;
            }
            else if (sum == k)
            {
                return true;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};