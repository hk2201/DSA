class Solution
{
public:
    int ans = 0;
    vector<int> dfs(TreeNode *root)
    {
        if (!root)
            return {INT_MAX, INT_MIN, 0};

        vector<int> L = dfs(root->left);
        vector<int> R = dfs(root->right);

        int v = root->val;

        if (L[1] < v && v < R[0])
        {
            // subtree from root is a BST
            int sum = L[2] + R[2] + v;
            ans = max(ans, sum);

            return {min(v, L[0]), max(v, R[1]), sum};
        }
        else
        {
            return {INT_MIN, INT_MAX, 0};
        }
    }
    int maxSumBST(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};

// MY APPROACH

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
    bool check(TreeNode *root, long minval, long maxval)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val >= maxval || root->val <= minval)
        {
            return false;
        }

        return check(root->left, minval, root->val) && check(root->right, root->val, maxval);
    }

    bool isBST(TreeNode *root)
    {
        return check(root, LONG_MIN, LONG_MAX);
    }

    int totalsum(TreeNode *root, int &ans)
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
                ans += node->val;
                node = node->right;
            }
        }
        return ans;
    }

    int maxSumBST(TreeNode *root)
    {
        // if(root->left->val > root->val || root->right->val < root->val){
        //     return NULL;
        // }
        int ans = 0;
        int maxx = 0;
        // root->left = isBST(root->left);
        // root->right = isBST(root->right);

        // while(root!=NULL){
        TreeNode *node = root;
        if (isBST(node))
        {
            totalsum(node, ans);
            maxx = max(ans, maxx);
            ans = 0;
        }
        else if (node->left != NULL)
        {
            node = node->left;
        }
        else if (node->right != NULL)
        {
            node = node->right;
        }

        // }

        return maxx;
    }
};