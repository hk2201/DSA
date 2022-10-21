class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        Node *temp = node->right;
        node->right = node->left;
        node->left = temp;

        mirror(node->right);
        mirror(node->left);
    }
};