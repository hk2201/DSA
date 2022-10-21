class Solution
{
public:
    vector<int> inorderTraversal(Node *root, vector<int> &ans)
    {
        stack<Node *> st;
        Node *node = root;

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
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }

    int kthLargest(Node *root, int k)
    {
        vector<int> ans;
        inorderTraversal(root, ans);
        int large = ans[ans.size() - k];

        return large;
    }
};