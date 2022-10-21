int findCeil(BinaryTreeNode<int> *node, int x)
{
    int num = -1;
    while (node != NULL)
    {
        if (node->data == x)
        {
            num = node->data;
            return num;
        }

        if (node->data < x)
        {

            node = node->right;
        }
        else
        {
            num = node->data;
            node = node->left;
        }
    }
    return num;
}