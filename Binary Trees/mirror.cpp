void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    BinaryTreeNode<int> *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
