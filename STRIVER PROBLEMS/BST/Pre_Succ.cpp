
void succ(Node *root, Node *&suc, int key)
{
    while (root != NULL)
    {
        if (key >= root->key)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}

void pree(Node *root, Node *&pre, int key)
{
    while (root != NULL)
    {
        if (key <= root->key)
        {

            root = root->left;
        }
        else
        {

            pre = root;
            root = root->right;
        }
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = NULL;
    suc = NULL;

    pree(root, pre, key);

    succ(root, suc, key);
}
