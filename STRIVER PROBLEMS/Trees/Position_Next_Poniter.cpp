/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root == NULL)
        {
            return NULL;
        }
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                if (size - 1 == i)
                {
                    node->next = NULL;
                }

                if (size - 1 != i)
                {
                    node->next = q.front();
                }

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
        }
        return root;
    }
};

// OPTIMAL

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->left != NULL)
        {
            root->left->next = root->right;
        }

        if (root->right != NULL && root->next != NULL)
        {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};